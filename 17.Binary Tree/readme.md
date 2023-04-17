## 1,2,3,4,5)Tree Traversal

                Tree traversal using Morris Traversal

## 6)Binary Tree Right Side View

## 7)Bottom View of Binary Tree

        use map for storing horizontal distance and queue for level order traversal

## 8)Top View of Binary Tree

        same os bottom view except keep the first element in map

## 9)All traversal in on go

        Approach:

                The algorithm steps can be described as follows:

                We take a stack data structure and push a pair<val, num> to it. Here Val is 
                the value of the root node and num the visit to the node. Initially, the num 
                is 1 as we are visiting the root node for the first time. We also create 
                three separate lists for preorder, inorder and postorder traversals. Then we 
                set an iterative loop to run till the time our stack is non-empty.


                In every iteration, we pop the top of the stack (say, T). Then we check the 
                second value(num) of T. Three cases can arise:


                Case 1 : When num==1
                This means that we are visiting the node for the very first time, therefore 
                we push the node value to our preorder list. Then we push the same node with 
                num=2(for Case 2). After this, we want to visit the left child. Therefore we 
                make a new pair Y(<val, num>) and push it to the stack (if there exists a 
                left child). The val of Y is equal to the left child’s node value and num is 
                equal to 1.


                Case 2 : When num==2
                This means that we are visiting the node for the second time, therefore on 
                our second visit to the node, we push the node value to our inorder list. 
                Then we push the same node with num=3( for Case 3). After this, we want to 
                visit the right child. Therefore as in the first case, we check if there 
                exists a right child or not. If there is, we push the right child and num 
                value=1 as a pair to our stack.


                Case 3 When num==3
                This means that we are visiting the node for the third time. Therefore we 
                will push that node’s value to our postorder list. Next, we simply want to 
                return to the parent so we will not push anything else to the stack
                

## 10)Vertical Order Traversal of a Binary Tree

        use map<int,map<int,multiset<int>>>
