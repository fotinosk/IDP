#mask contours

import numpy as np
import cv2

def cont(img):
#im = cv2.imread('full_track3.jpg')
    imgray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    ret,thresh = cv2.threshold(imgray,127,255,0)
    contours, hierarchy = cv2.findContours(thresh, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        if cv2.contourArea(contour) > 40:
            img = cv2.drawContours(img, contour, -1, (0, 255, 255), 2)
        
#cv2.imshow('contours',img)
    cv2.imwrite('c.jpg',img)
#cv2.waitKey(0)
#cv2.destroyAllWindows()
    
'''
img = cv2.drawContours(im, contours, -1, (0,255,0), 1)
cv2.imshow('contours',img)
#cv2.imwrite('c.jpg',img)

cv2.waitKey(0)
cv2.destroyAllWindows()
'''