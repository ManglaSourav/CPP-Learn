#include<iostream>
#include<queue>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node *buildTree() {
    int d;
    cin >> d;
    if (d == -1) {
        return NULL;
    }
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void levelOrderPrint(node *head) {
    queue<node *> q;
    q.push(head);
    q.push(NULL);
    while (!q.empty()) {
        node *temp = q.front();
        if (temp == NULL) {
            cout << endl;
//           encountered level end or tree end
            q.pop();
            if (!q.empty()) {
//                handling edge case;
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            q.pop();
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return;
}

//1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1 -1
node *levelOrderbuid() {
    int d;
    cin >> d;
    node *root = new node(d);

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *temp = q.front();
        if (temp == NULL) {
            q.pop();
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            q.pop();
            int a, b;
            cin >> a;
            cin >> b;
            if (a != -1) {
                temp->left = new node(a);
                q.push(temp->left);
            }
            if (b != -1) {
                temp->right = new node(b);
                q.push(temp->right);
            }
        }
    }


    return root;
}


class HDPair {
public:
    int diameter;
    int height;
};

HDPair diameterOfTree(node *root) {

    HDPair p;
    if (root == NULL) {
        p.diameter = p.height = 0;
        return p;
    }

    HDPair left = diameterOfTree(root->left);
    HDPair right = diameterOfTree(root->right);

    p.height = max(left.height, right.height) + 1;

    int d1 = left.height + right.height;
    int d2 = left.diameter;
    int d3 = right.diameter;

    p.diameter = max(d1, max(d2, d3));

    return p;

}

int main() {
    cout << "Enter node values = ";
//    node *root = buildTree();
    node *root = levelOrderbuid();
    levelOrderPrint(root);
    cout << "Diameter = " << diameterOfTree(root).diameter << endl;
    return 0;
}

