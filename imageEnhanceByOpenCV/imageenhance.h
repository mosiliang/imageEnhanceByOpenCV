#ifndef IMAGEENHANCE_H
#define IMAGEENHANCE_H

#include <QMainWindow>

namespace Ui {
class imageEnhance;
}
enum enhanceMeans
{
	SharpenMedian = 0,
	Contrast = 1
};
class imageEnhance : public QMainWindow
{
    Q_OBJECT

public:
    explicit imageEnhance(QWidget *parent = 0);
    ~imageEnhance();
public slots:
	void on_means1_clicked();
	void on_means2_clicked();
private:
	bool doImageEnhance(int means);

private:
    Ui::imageEnhance *ui;
};

#endif // IMAGEENHANCE_H
