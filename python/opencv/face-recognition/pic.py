import cv2

image_path      = "./pc1.png"
facedata_path   = "./haarcascade_frontalface_default.xml"
face_cascade    = cv2.CascadeClassifier(facedata_path)

image   = cv2.imread(image_path)
gray    = cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
cv2.imshow("Picture",image)
cv2.waitKey(0)
faces = face_cascade.detectMultiScale(
        gray,
        scaleFactor = 1.15,
        minNeighbors= 5,
        minSize     = (5,5),
        flags       = cv2.CASCADE_SCALE_IMAGE
        )

print('hello')
print("find {0} face(s)!",format(len(faces)))

for(x,y,w,h) in faces:
    cv2.circle(image,((x+x+w)/2,(y+y+h)/2),w/2,(0,255,0),2)

cv2.imshow("Find Faces!",image)
cv2.waitKey(0)
