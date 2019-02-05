#full code
import numpy as np
import cv2
import os

from lane_detection import res
from contours import cont
#import dist_c2c

image = cv2.imread('cropped.jpg',1)
res(image)

img = cv2.imread('res.jpg')
cont(img)

os.system('python dist_c2c.py')