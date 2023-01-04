import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt
img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

blank = np.zeros(img.shape[:2], dtype='uint8')

# gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow("gray", gray)

circle = cv.circle(blank, (img.shape[1]//2, img.shape[0]//2), 100, 255, -1)
# mask = cv.bitwise_and(gray, gray, mask=circle)
mask = cv.bitwise_and(img, img, mask=circle)
cv.imshow('mask', mask)

# grayscale histogram
# gray_hist = cv.calcHist([gray], [0], mask, [256], [0, 256])

# plt.figure()
# plt.title('grayscale histogream')
# plt.xlabel('Bins')
# plt.ylabel('# of pixels')
# plt.plot(gray_hist)
# plt.xlim([0, 256])
# plt.show()

plt.figure()
plt.title('Colour histogream')
plt.xlabel('Bins')
plt.ylabel('# of pixels')

# colour higtogram
colors = ('b', 'g', 'r',)
for i, col in enumerate(colors):
    hist = cv.calcHist  ([img], [i], None, [256], [0, 256])
    plt.plot(hist, color=col)
    plt.xlim([0, 256])
    
plt.show()
cv.waitKey(0)
