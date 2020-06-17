import numpy as np
import cv2

img = np.zeros((512,512,3),np.uint8)

img = cv2.line(img,(0,0),(511,511),(255,0,0),5)
img = cv2.rectangle(img,(511-512//4,0),(511,512//4),(0,255,0),2)
img = cv2.circle(img,(511-512//8,512//8),512//8,(0,0,255),-1)
img = cv2.ellipse(img,(512//2-1,512//2-1),(512//6,512//16),45,180,90,(255,0,0),-1)

font = cv2.FONT_HERSHEY_SIMPLEX
cv2.putText(img,'Emir-Liu',(0,511-512//4),font,3,(255,255,255),2,cv2.LINE_AA)

cv2.imshow('pic',img)
cv2.waitKey(0)
