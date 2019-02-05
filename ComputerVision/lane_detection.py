#lane detection

import numpy as np
import cv2

def res(img):
    #img = cv2.imread('full_track3.jpg',1) # 0 is grayscale, 1 is color
    #cv2.imshow('image',img)


    hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    lower_blue = np.array([100,70,70])
    upper_blue = np.array([150,255,255])
    
#lower_red = np.array([0,110,120])
#upper_red = np.array([70,255,255])

    mask = cv2.inRange(hsv, lower_blue, upper_blue)
#mask2 = cv2.inRange(hsv, lower_red, upper_red)
#mask3 = cv2.add(mask,mask2)
    res = cv2.bitwise_and(img,img, mask= mask)

#cv2.imshow('image',img)
#cv2.imshow('mask',mask)
#cv2.imshow('res',res)
    cv2.imwrite('res.jpg',res)

#cv2.waitKey(0)
#cv2.destroyAllWindows()

