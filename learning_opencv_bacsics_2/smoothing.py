import cv2 as cv
import numpy as np

img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

# averaging
# average = cv.blur(img, (3, 3))
average = cv.blur(img, (7, 7))
cv.imshow('Average blur', average)

# Gaussian blur
# gauss = cv.GaussianBlur(img, (3, 3), 0)
gauss = cv.GaussianBlur(img, (7, 7), 0)
cv.imshow('gaussian blur', gauss)

# median blur
median = cv.medianBlur(img, 7)
cv.imshow('median blur', median)

# bilateral
bilateral = cv.bilateralFilter(img, 5, 15, 15)
cv.imshow('bilateral', bilateral)

cv.waitKey(0)
