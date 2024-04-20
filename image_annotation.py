import cv2 as cv

img = cv.imread("/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/free-nature-images.jpg")
if img is None:
    print("Image is empty")
else:
    print("Image is not empty")
image = cv.putText(img, 'Nature', (50, 50), cv.FONT_HERSHEY_SIMPLEX,
                   1, (255, 0, 0), 2, cv.LINE_AA)
text_image = img.copy()
line_image = img.copy()
rectangle_image = img.copy()
circle_image = img.copy()

cv.putText(text_image, 'Nature', (50, 50), cv.FONT_HERSHEY_SIMPLEX,
           1, (255, 0, 0), 2, cv.LINE_AA)
cv.line(line_image, (0, 0), (511, 511), (255, 0, 0), 5)
cv.rectangle(rectangle_image, (384, 0), (510, 128), (0, 255, 0), 3)
cv.circle(circle_image, (447, 63), 63, (0, 0, 255), -1)

cv.imshow("Texted Image", text_image)
cv.imshow("Line Image", line_image)
cv.imshow("Rectangle Image", rectangle_image)
cv.imshow("Circle Image", circle_image)
cv.waitKey(0)
cv.destroyAllWindows()

texted_image = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/textedimage.jpg'
line = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/line.jpg'
rectangle = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/rectangle.jpg'
circle = '/home/maria/Desktop/Picsart Academy /project_ds/pythonProject1/circle.jpg'
cv.imwrite(texted_image, image)
cv.imwrite(line, line_image)
cv.imwrite(rectangle, rectangle_image)
cv.imwrite(circle, circle_image)
