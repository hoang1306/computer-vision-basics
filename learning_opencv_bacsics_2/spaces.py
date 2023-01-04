import cv2 as cv
# import numpy as np
import matplotlib.pyplot as plt
img = cv.imread("../Resources/Photos/cats.jpg")
cv.imshow('Cats', img)
# plt.imshow(img)
# plt.show()
# BGR to Grayscale
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)

# BGR to HSV
hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
cv.imshow('hsv', hsv)

# BGR to Lab
lab = cv.cvtColor(img, cv.COLOR_BGR2LAB)
cv.imshow('lab', lab)

# BGR to RGB
rgb = cv.cvtColor(img, cv.COLOR_BGR2RGB)
cv.imshow('RGB', rgb)

# hsv to bgr
hsv_to_bgr = cv.cvtColor(hsv, cv.COLOR_HSV2BGR)

cv.imshow('hsv --> bgr', hsv_to_bgr)

plt.imshow(hsv_to_bgr)
plt.show()

cv.waitKey(0)
