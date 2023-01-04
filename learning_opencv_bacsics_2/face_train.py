import os
import cv2 as cv
import numpy as np

people = ['Madonna', 'Ben Afflek', 'Mindy Kaling',
          'Jerry Seinfield', 'Elton John']
root_path = r'../Resources/Faces/train'

haar_cascade = cv.CascadeClassifier('../data_model/haar_face.xml')
# name_folder = []
# for i in os.listdir(root_path):
#     name_folder.append(i)
# print(name_folder)


def create_train():
    features = []
    labels = []
    for person in people:
        path = os.path.join(root_path, person)
        label = people.index(person)

        for img in os.listdir(path):
            img_path = os.path.join(path, img)

            img_array = cv.imread(img_path)
            gray = cv.cvtColor(img_array, cv.COLOR_BGR2GRAY)

            faces_rect = haar_cascade.detectMultiScale(
                gray, scaleFactor=1.1, minNeighbors=4)

            for (x, y, w, h) in faces_rect:
                faces_roi = gray[y:y+h, x:x+w]
                features.append(faces_roi)
                labels.append(label)
    return features, labels


features, labels = create_train()
print('training =======================> done')
# print(f'Length of the features =  {len(features)}')
# print(f'Length of the labels = {len(labels)}')
# print(features)
# print(labels)
features = np.array(features, dtype='object')
labels = np.array(labels)

face_recognizer = cv.face.LBPHFaceRecognizer_create()

# train the recognizer on the features list and the labels list

face_recognizer.train(features, labels)
face_recognizer.save('face_trained.yml')
np.save('features.npy', features)
np.save('labels.npy', labels)
