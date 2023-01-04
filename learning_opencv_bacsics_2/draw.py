import cv2 as cv
import numpy as np
# color
blank = np.zeros((500, 500, 3), dtype='uint8')
# cv.imshow('Blank', blank)
# img = cv.imread('../Resources/Photos/cat.jpg')
# cv.imshow("Cat", img)
# 1. paint the image a certain colour
# blank[100:200, 200:300] = 0, 255, 0

# 2. Draw a rectangle
# cv.rectangle(blank, (0, 0), (300, 300), (0, 255, 0), thickness=2)
cv.rectangle(blank, (0, 0), (blank.shape[1]//2, blank.shape[0]//2), (0, 255, 0), thickness=-1)
# cv.rectangle(blank, (0, 0), (300, 300), (0, 255, 0), thickness=cv.FILLED)
# cv.imshow('rectangle', blank)

# 3. Draw a circle
cv.circle(blank, (blank.shape[1]//2, blank.shape[0]//2), 50, (0, 0, 255), thickness=-1)
cv.imshow('circle', blank)

# 4. draw a line
cv.line(blank, (400, 400), (blank.shape[1]//2, blank.shape[0]//2), (255, 255, 255), thickness=3)
cv.imshow('line', blank)

# 5. write text
cv.putText(blank, 'Hello', (255,255), cv.FONT_HERSHEY_COMPLEX, 1.0, (0, 255, 0), 2)
cv.imshow('Text', blank)

cv.waitKey(0)
