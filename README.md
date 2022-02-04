# Simple-Cache-Buffer-in-C

Data Structures and Algorithms Class 2019-2020

Design and Implement a cache buffer using doubly linked list data structure. This cache buffer will be used to provide quality service and priority for a network environment by storing the web page requests.

Cache Buffer Features:<br/>
  a. Every node of the linked list stores the address of the requested page, the number of request for this page and the pointers to the previous and the next nodes.<br/>
  b. Includes functions for traversing the nodes, getting number of requests on a page, adding new page and deleting a page.<br/>
  c. Ability to read the requested pages as string from user and a text file<br/>
  d. New pages will be read from the file and a new node will be created with page counter as 1 and will be added to the head node of the linked list.<br/>
  e. If the count of an input page surpassed the given threshold value then its node is made head node<br/>
  f. If the lenth of the cache buffer surpassed given length value the last element is deleted<br/>
  g. Ability to clean the linked list<br/>
  <br/>
![Screenshot 2021-11-28 112739](https://user-images.githubusercontent.com/49107892/143735243-bc09319d-6bb5-49de-a869-90efd83a36c5.png)
