# Simple-Cache-Buffer-in-C

Data Structures and Algorithms Class 2019-2020

Design and Implement a cache buffer using doubly linked list data structure. This cache buffer will be used to provide quality service and priority for a network environment by storing the web page requests.

Cache Buffer Features:<br/>
  a. Every node of the linked list stores requested page adress, number of request for this page and pointers to the previous and next nodes.<br/>
  b. Functions for traversing the nodes, getting number of requests on a page, adding new page and deleting a page.<br/>
  c. Read the requested pages as string from user and a text file<br/>
  d. New pages will be read from the file and a new node will be created with page counter as 1 and will be added to the head node of the linked list.<br/>
  e. If the count of an input page surpassed a threshold value of 10 then its node is made head node<br/>
  f. If the lenth of the cache buffer surpassed 20 the last element is deleted<br/>
  <br/>
![Screenshot 2021-11-28 112739](https://user-images.githubusercontent.com/49107892/143735243-bc09319d-6bb5-49de-a869-90efd83a36c5.png)
