
1) createplatform creates a platform named a which i have declared outside as it only made for 1 instance, i took a int plat to check if it has been made or not

2) my last viewed post is NULL till you view a post,if you delete a lastviewed post then the recent post becomes last viewed post, next,current and previous posts changes last viewed post

3) i created a void remove content for my ease of deleting content

4) I can't add a comment until you view a post, or if no post exists

5) similarly for replies you can't add if there doesn;t exist a last viewed post or comment (according to the number)

6) you can't delete a comment or reply that doesn't exist

7) I made all structures of post , comment , and reply doubly linked list and also kept a pointer of end comment or reply for adding and deleting at O(1)

8) I have taken input in form of arrays of size 100 char ,for username,comment,reply,caption,etc

9) it will take input till enter is pressed , since even for each command all inputs are given in different lines

10) my programme runs infinitely, to exit press ctrl+c