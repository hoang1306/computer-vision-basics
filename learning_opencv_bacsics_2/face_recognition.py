import cv2 as cv
import numpy as np

root_path_val = r'../Resources/Faces/val/elton_john'

people = ['Madonna', 'Ben Afflek', 'Mindy Kaling',
          'Jerry Seinfield', 'Elton John']

haar_cascade = cv.CascadeClassifier('../data_model/haar_face.xml')

features = np.load('features.npy', allow_pickle=True)
labels = np.load('labels.npy', allow_pickle=True)

face_recognizer = cv.face.LBPHFaceRecognizer_create()

face_recognizer.read('face_trained.yml')

img = cv.imread(root_path_val + "/1.jpg")
# img = cv.imread("../images/justin_biber.jpg")


gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('person', gray)

# detect the face in the image
faces_rect = haar_cascade.detectMultiScale(gray, 1.1, 4)

for (x, y, w, h) in faces_rect:
    faces_roi = gray[y:y+h, x:x+w]
    label, confidence = face_recognizer.predict(faces_roi)
    print(f'label = {people[label]} with a confidence of {confidence}')
    cv.putText(img, str(people[label]), (20, 20),
               cv.FONT_HERSHEY_COMPLEX, 1.0, (0, 255, 0), thickness=2)
    cv.rectangle(img, (x, y), (x+w, y+h), (0, 255, 0), thickness=2)

cv.imshow('detected face', img)
cv.waitKey(0)
