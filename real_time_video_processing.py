import cv2
import datetime

cap = cv2.VideoCapture(0)
current_effect = "Normal"

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    if current_effect == "Grayscale":
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    elif current_effect == "HSV":
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    elif current_effect == "LAB":
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2Lab)
    elif current_effect == "Blur":
        frame = cv2.GaussianBlur(frame, (15, 15), 0)
    elif current_effect == "Median Filter":
        frame = cv2.medianBlur(frame, 15)
    elif current_effect == "Flip Vertically":
        frame = cv2.flip(frame, 0)
    elif current_effect == "Flip Horizontally":
        frame = cv2.flip(frame, 1)
    elif current_effect == "Rotate":
        frame = cv2.rotate(frame, cv2.ROTATE_90_CLOCKWISE)
    elif current_effect == "Draw Rectangle":
        cv2.rectangle(frame, (50, 50), (200, 200), (255, 0, 0), 2)

    current_time = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    cv2.putText(frame, f"Effect: {current_effect}", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
    cv2.putText(frame, f"Time: {current_time}", (10, 60), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)

    cv2.imshow("Webcam Feed", frame)

    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        break
    elif key == ord("g"):
        current_effect = "Grayscale"
    elif key == ord("h"):
        current_effect = "HSV"
    elif key == ord("l"):
        current_effect = "LAB"
    elif key == ord("b"):
        current_effect = "Blur"
    elif key == ord("m"):
        current_effect = "Median Filter"
    elif key == ord("v"):
        current_effect = "Flip Vertically"
    elif key == ord("x"):
        current_effect = "Flip Horizontally"
    elif key == ord("r"):
        current_effect = "Rotate"
    elif key == ord("d"):
        current_effect = "Draw Rectangle"

cap.release()
cv2.destroyAllWindows()
