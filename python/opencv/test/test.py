import cv2

img_path = "./pc1.png"

img = cv2.imread(img_path,0)
cv2.imshow("pic",img)
k = cv2.waitKey(0) & 0xFF

if k==27: #wait for ESC to exit
    cv2.destroyAllWindows()
elif k == ord('s') #wait for 's' key to save
    cv2.imwrite('backup.png',img)
