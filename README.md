# imageEnhanceByOpenCV
Includes several means to enhance images by OpenCV.

## x86 debug

Choose one means and choose a file folder includes images.
</br>
Waiting for several time, do not push button in a short time.
</br>
Program will create a new folder and create enhanced images in it.

## 1 | filter-sharpen-median
transform image histogram : balance brightness and contrast.
</br>
bilateral filter : protect edges and remove noise.
</br>
laplacian sharpen : make images clear.
</br>
median filter : remove noise(mostly salty noise).

## 2 | filter-contrast
transform image histogram : balance brightness and contrast.
</br>
bilateral filter : protect edges and remove noise.
</br>
convolves an image with kernel : enhance contrast.



# Plan
## 1 |  transform histogram by adaptive threshold
## 2 |	controllable parameters by users
## 3 |	insert another means
