import cv2 as cv

img = cv.imread("../Resources/Photos/cats.jpg")
cv.imshow("cats", img)

gray =cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow("gray", gray)

# simple thresholding
threshold, thresh = cv.threshold(gray, 150, 255, cv.THRESH_BINARY)
cv.imshow('simple thresholded', thresh)

threshold, thresh_inv = cv.threshold(gray, 150, 255, cv.THRESH_BINARY_INV)
cv.imshow('simple thresholded inverse', thresh_inv)

# adaptive thresholding
adaptive_thresh = cv.adaptiveThreshold(gray, 255, cv.ADAPTIVE_THRESH_MEAN_C, cv.THRESH_BINARY_INV, 13, 11)
cv.imshow('adaptive thresholding', adaptive_thresh)

cv.waitKey(0)