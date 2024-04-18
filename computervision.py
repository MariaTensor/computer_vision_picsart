import cv2


img = cv2.imread("/home/maria/Pictures/Screenshots/Screenshot from 2023-09-28 19-25-57.png")

cv2.imshow('image', img)
cv2.waitKey(0)
cv2.destroyAllWindows()