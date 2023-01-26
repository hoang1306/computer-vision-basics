import cv2 as cv


img = cv.imread('../Resources/Photos/cat.jpg')
cv.imshow('Cat',img)
# converting to grayscale
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow('gray', gray)
# blur
# blur = cv.GaussianBlur(img, (3, 3), cv.BORDER_DEFAULT)
blur = cv.GaussianBlur(img, (7, 7), cv.BORDER_DEFAULT)
# cv.imshow('Blur', blur)

# edge cascade
cany = cv.Canny(blur, 125, 175)
cv.imshow('Canny edge', cany)

# dilating the image
dilated = cv.dilate(cany, (3, 3), iterations=1)
cv.imshow('dilated', dilated)

# eroding
eroding = cv.erode(dilated, (3, 3), iterations=1)
cv.imshow('eroded', eroding)

# resize
resized = cv.resize(img, (500, 500), interpolation=cv.INTER_CUBIC)
cv.imshow("Resize", resized)

# Cropping
cropped = img[50:250, 200:400]
cv.imshow("cropped", cropped)

cv.waitKey(0)