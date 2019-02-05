# import the necessary packages
from scipy.spatial import distance as dist
from imutils import perspective
from imutils import contours
import numpy as np
import imutils
import cv2
 
def midpoint(ptA, ptB):
	return ((ptA[0] + ptB[0]) * 0.5, (ptA[1] + ptB[1]) * 0.5)
 
image = cv2.imread('c.jpg')
#img = cv2.imread('full_track3.jpg')

width = 608 # <---- only if cropped, else 768
height = 608
dim = (width,height)

image = cv2.resize(image, dim, interpolation = cv2.INTER_AREA)
#img = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
gray = cv2.GaussianBlur(gray, (7, 7), 0)

edged = cv2.Canny(gray, 50, 100)
edged = cv2.dilate(edged, None, iterations=1)
edged = cv2.erode(edged, None, iterations=1)
 
cnts = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL,
	cv2.CHAIN_APPROX_SIMPLE)
cnts = imutils.grab_contours(cnts)

(cnts, _) = contours.sort_contours(cnts)
colors = ((0, 0, 255), (240, 0, 159), (0, 165, 255), (255, 255, 0),
	(255, 0, 255))
refObj = None

for c in cnts:
	
	#if cv2.contourArea(c) < 50:
	#	continue
 
	box = cv2.minAreaRect(c)
	box = cv2.cv.BoxPoints(box) if imutils.is_cv2() else cv2.boxPoints(box)
	box = np.array(box, dtype="int")
	box = perspective.order_points(box)

	cX = np.average(box[:, 0])
	cY = np.average(box[:, 1])

	if refObj is None:
		box = np.array([[0,0],[width,0],[width,height],[0,height]])
		#print(box)
		(tl, tr, br, bl) = box
		(tlblX, tlblY) = midpoint(tl, bl)
		(trbrX, trbrY) = midpoint(tr, br)
 
		cX = np.average(box[:, 0])
		cY = np.average(box[:, 1])

		#(tltrX, tltrY) = midpoint(tl, tr) #test
		#(blbrX, blbrY) = midpoint(bl, br)
        
		D = dist.euclidean((tlblX, tlblY), (trbrX, trbrY))

		#D = dist.euclidean((tltrX, tltrY), (blbrX, blbrY))

		refObj = (box, (cX, cY), D / 2400)
		continue
    
	# draw the contours on the image
	orig = image.copy()
	cv2.drawContours(orig, [box.astype("int")], -1, (0, 255, 0), 2)
	cv2.drawContours(orig, [refObj[0].astype("int")], -1, (0, 255, 0), 2)
 
	refCoords = np.vstack([refObj[0], refObj[1]])
	objCoords = np.vstack([box, (cX, cY)])
    
	for ((xA, yA), (xB, yB), color) in zip(refCoords, objCoords, colors):
		cv2.circle(orig, (int(xA), int(yA)), 5, color, -1)
		cv2.circle(orig, (int(xB), int(yB)), 5, color, -1)
		cv2.line(orig, (int(xA), int(yA)), (int(xB), int(yB)),
			color, 2)

		X = (abs(yA-yB)) / refObj[2]
		D = dist.euclidean((xA, yA), (xB, yB)) / refObj[2]
		(mX, mY) = midpoint((xA, yA), (xB, yB))
		cv2.putText(orig, "{:.1f}mm, {:.1f}mm".format(D,X), (int(mX - 80), int(mY - 10)),
			cv2.FONT_HERSHEY_SIMPLEX, 0.55, color, 2)
 
		#res = cv2.bitwise_and(img,img, mask= orig)
		#cv2.imshow("res", res)
		cv2.imshow("Image", orig)
		cv2.waitKey(0)