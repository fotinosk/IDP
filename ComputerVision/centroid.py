import numpy as np
import cv2 as cv
img = cv.imread('c.jpg',0)
ret,thresh = cv.threshold(img,127,255,0)
contours,hierarchy = cv.findContours(thresh, 1, 2)


for i in range(len(contours)):
#cnt = contours[2] #1st contour
    cnt = contours[i]
    M = cv.moments(cnt)
    cx = int(M['m10']/M['m00'])
    cy = int(M['m01']/M['m00']) #only care about cy, rotate image the right way

    print((cx,cy))