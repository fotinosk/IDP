import numpy as np
import cv2
 
img = cv2.imread('c.jpg')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
 
ret,thresh = cv2.threshold(gray,127,255,1)
 
#contours,h = cv2.findContours(thresh,1,2)
contours, h = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
 
for cnt in contours:
    approx = cv2.approxPolyDP(cnt,0.17*cv2.arcLength(cnt,True),True)
    if len(approx)==4:
        #print("square")
        cv2.drawContours(img,[cnt],0,(0,0,255),-1)
 
cv2.imshow('img',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
