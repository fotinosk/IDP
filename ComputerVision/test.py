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
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
gray = cv2.GaussianBlur(gray, (7, 7), 0)

edged = cv2.Canny(gray, 50, 100)
edged = cv2.dilate(edged, None, iterations=1)
edged = cv2.erode(edged, None, iterations=1)

cnts = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL,
	cv2.CHAIN_APPROX_SIMPLE)
cnts = imutils.grab_contours(cnts)
 
# sort the contours from left-to-right and, then initialize the
# distance colors and reference object
(cnts, _) = contours.sort_contours(cnts)
colors = ((0, 0, 255), (240, 0, 159), (0, 165, 255), (255, 255, 0),
	(255, 0, 255))
refObj = None

# loop over the contours individually
for c in cnts:
	# if the contour is not sufficiently large, ignore it
	if cv2.contourArea(c) < 100:
		continue
 
	# compute the rotated bounding box of the contour
	box = cv2.minAreaRect(c)
	box = cv2.cv.BoxPoints(box) if imutils.is_cv2() else cv2.boxPoints(box)
	box = np.array(box, dtype="int")
 
	# order the points in the contour such that they appear
	# in top-left, top-right, bottom-right, and bottom-left
	# order, then draw the outline of the rotated bounding
	# box
	box = perspective.order_points(box)
 
	# compute the center of the bounding box
	cX = np.average(box[:, 0])
	cY = np.average(box[:, 1])

	# if this is the first contour we are examining (i.e.,
	# the left-most contour), we presume this is the
	# reference object
	if refObj is None:
		# unpack the ordered bounding box, then compute the
		# midpoint between the top-left and top-right points,
		# followed by the midpoint between the top-right and
		# bottom-right
		(tl, tr, br, bl) = box
		(tlblX, tlblY) = midpoint(tl, bl)
		(trbrX, trbrY) = midpoint(tr, br)
 
		# compute the Euclidean distance between the midpoints,
		# then construct the reference object
		D = dist.euclidean((tlblX, tlblY), (trbrX, trbrY))
		refObj = (box, (0, 0), D / 2.4)
		continue
    
	# draw the contours on the image
	orig = image.copy()
	cv2.drawContours(orig, [box.astype("int")], -1, (0, 255, 0), 2)
	#cv2.drawContours(orig, [refObj[0].astype("int")], -1, (0, 255, 0), 2)
 
	# stack the reference coordinates and the object coordinates
	# to include the object center
	refCoords = np.vstack([refObj[0], refObj[1]])
	objCoords = np.vstack([box, (cX, cY)])
    
    	# loop over the original points
	for ((xA, yA), (xB, yB)) in zip(refCoords, objCoords):
		yB = objCoords[4][1]
		xB = objCoords[4][0]
		cv2.circle(orig, (0, 0), 3, (255, 255, 0), -1)
		cv2.circle(orig, (int(xB), int(yB)), 3, (255, 255, 0), -1)
		cv2.line(orig, (0, 0), (int(xB), int(yB)), (255, 255, 0), 2)
 
		# compute the Euclidean distance between the coordinates,
		# and then convert the distance in pixels to distance in
		# units
		D = dist.euclidean((0, 0), (xB, yB)) / refObj[2]
		(mX, mY) = midpoint((0,0), (xB, yB)) #where to place the text
		cv2.putText(orig, "{:.1f}mm".format(D), (int(mX), int(mY - 10)),
			cv2.FONT_HERSHEY_SIMPLEX, 0.55, (255, 255, 0), 2)
 
		# show the output image
		cv2.imshow("Image", orig)
		cv2.waitKey(0)