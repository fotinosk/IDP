import cv2
import numpy as np

cap = cv2.VideoCapture(1)

while(1):

    # Take each frame
    _, frame = cap.read()

    # Convert BGR to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # define range of blue color in HSV
    lower_blue = np.array([100,70,70])
    upper_blue = np.array([150,255,255])
    
    lower_red = np.array([0,110,120])
    upper_red = np.array([70,255,255])

    # Threshold the HSV image to get only blue colors
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    mask2 = cv2.inRange(hsv, lower_red, upper_red)
    mask3 = cv2.add(mask,mask2)

    # Bitwise-AND mask and original image
    #res = cv2.bitwise_and(frame,frame, mask= mask)
    #res2 = cv2.bitwise_and(frame,frame, mask= mask2)
    res3 = cv2.bitwise_and(frame,frame, mask= mask3)
    

    cv2.imshow('frame',frame)
    #cv2.imshow('mask',mask)
    #cv2.imshow('mask2',mask2)
    
    cv2.imshow('mask3',mask3)
    
    #cv2.imshow('res',res)
    #cv2.imshow('res2',res2)
    cv2.imshow('res3',res3)
    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()

#noises in the images can be removed
#https://opencv-python-tutroals.readthedocs.io/en/latest/py_tutorials/py_imgproc/py_colorspaces/py_colorspaces.html#converting-colorspaces