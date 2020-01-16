#include "imageenhance.h"
#include "ui_imageenhance.h"
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <Qtime>
#include <QMessageBox>
#include "opencv.h"

imageEnhance::imageEnhance(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::imageEnhance)
{
    ui->setupUi(this);
}

imageEnhance::~imageEnhance()
{
    delete ui;
}

void imageEnhance::on_means1_clicked()
{
	QMessageBox mesBox;
	if (doImageEnhance(SharpenMedian))
	{
		qDebug() << "Success.";
		mesBox.setText("Success.");
	}
	else
	{
		qDebug() << "Fail.";
		mesBox.setText("Fail.");
	}
	mesBox.exec();
}

void imageEnhance::on_means2_clicked()
{
	QMessageBox mesBox;
	if (doImageEnhance(Contrast))
	{
		qDebug() << "Success.";
		mesBox.setText("Success.");
	}
	else
	{
		qDebug() << "Fail.";
		mesBox.setText("Fail.");
	}
	mesBox.exec();
}

bool imageEnhance::doImageEnhance(int means)
{
	QString fileFolder=QFileDialog::getExistingDirectory(NULL, QString(), QString());
	if (fileFolder.isEmpty())
	{
		qDebug() << "Cancel selecting directory.";
		return false;
	}
	else {
		QString newFileFolder = fileFolder;
		if (SharpenMedian == means)
		{
			newFileFolder.append("/filter-sharpen-median/");
		}
		else if (Contrast == means)
		{
			newFileFolder.append("/filter-contrast/");
		}
		QDir newFileDir(newFileFolder);
		QDir fileDir(fileFolder);
		if (!newFileDir.exists())
		{
			newFileDir.mkdir(newFileFolder);
		}
		fileDir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
		QFileInfoList fileInfoList = fileDir.entryInfoList();
		foreach(QFileInfo fileInfo, fileInfoList)
		{
			if (fileInfo.isFile())
			{
				QString strFilePath = fileInfo.filePath();
				Mat img = imread(strFilePath.toStdString()), newImg;
				if (!img.empty())
				{
					QString newFilePath;
					if (SharpenMedian == means)
					{
						newFilePath = newFileFolder + "1-" + fileInfo.fileName();
					}
					else if (Contrast == means)
					{
						newFilePath = newFileFolder + "2-" + fileInfo.fileName();
					}
					QTime time;
					time.start();
					Mat imgChannel[3];
					openCv opencv;
					split(img, imgChannel);
					for (int i = 0; i < 3; ++i)
					{
						imgChannel[i] = opencv.transLookup(imgChannel[i], 100);
					}
					merge(imgChannel, 3, newImg);
					if (SharpenMedian == means)
					{
						newImg = opencv.bilateral(newImg);
						newImg = opencv.laplacianSharpen(newImg);
						newImg = opencv.medianFilter(newImg);
						imwrite(newFilePath.toStdString(), newImg);
					}
					else if (Contrast == means)
					{
						newImg = opencv.bilateral(newImg);
						newImg = opencv.enhanceContrast(newImg);
						imwrite(newFilePath.toStdString(), newImg);
					}
					int t = time.elapsed();
					QFileInfo newFileInfo(newFilePath);
					qDebug() << fileInfo.fileName() << " *** " << fileInfo.size() << " --- " << newFileInfo.size() << " --- t:" << t;
				}
			}
		}
	}
	return true;
}
