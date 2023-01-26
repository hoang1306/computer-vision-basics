import cv2 as cv
import numpy as np


img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

blank = np.zeros(img.shape[:2], dtype='uint8')
cv.imshow('blank image', blank)

rectangle = cv.rectangle(blank.copy(), (30, 30), (370, 370), 255, -1)
circle = cv.circle(blank.copy(), (img.shape[1]//2 + 45, img.shape[0]//2), 100, 255, -1)

mask = cv.circle(blank, (img.shape[1]//2, img.shape[0]//2), 100, 255, -1)
cv.imshow('mask', mask)

weird_shape = cv.bitwise_and(circle, rectangle)
cv.imshow('weird shape', weird_shape)
masked = cv.bitwise_and(img, img, mask=mask)
cv.imshow('masked image', masked)
masked = cv.bitwise_and(img, img, mask=weird_shape)
cv.imshow('weird masked image', masked)
cv.waitKey(0)