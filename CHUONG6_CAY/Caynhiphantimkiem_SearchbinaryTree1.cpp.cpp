#include <iostream>
using namespace std;

class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int value) {
        data = value;
        left = right = NULL;
    }
};

// Ham them mot phan tu vao cay nhi phan tim kiem
int insert(int x, BSTNode*& root) {
    if (root == NULL) {
        root = new BSTNode(x); // Cap phat bo nho cho node moi
        if (root == NULL) {
            return -1; // Khong the cap phat bo nho
        } else {
            return 1; // Them thanh cong
        }
    } else {
        if (root->data == x) {
            return 0; // Gia tri da ton tai trong cay
        } else if (x < root->data) {
            return insert(x, root->left); // Di vao nhanh trai de them
        } else {
            return insert(x, root->right); // Di vao nhanh phai de them 
        }
    }
}

// Ham tim mot nut co khoa x
BSTNode* Find(int x, BSTNode* root) {
    if (root == NULL) return NULL;
    if (x < root->data) {
        return Find(x, root->left); // Tim o nhanh trai
    } else if (x > root->data) {
        return Find(x, root->right); // Tim o nhanh phai
    } else {
        return root; // Da tim thay
    }
}

// Ham tim nut co khoa nho nhat
BSTNode* Findmin(BSTNode* root) {
    if (root == NULL) return NULL;
    else if (root->left == NULL) return root;
    else return Findmin(root->left);
}

// Ham tim nut co khoa lon nhat
BSTNode* Findmax(BSTNode* root) {
    if (root != NULL) {
        while (root->right != NULL) {
            root = root->right;
        }
    }
    return root;
}

// Ham xoa mot nut co khoa x
int Delete(int x, BSTNode*& root) {
    BSTNode* p;
    if (root == NULL)
        return 0; // Cay rong, khong tim thay
    else if (x < root->data) // Xoa tren cay con trai
        return Delete(x, root->left);
    else if (x > root->data) // Xoa tren cay con phai
        return Delete(x, root->right);
    else { // Tim ra nut can xoa
        if (root->left && root->right) { // Co 2 con
            p = Findmax(root->left); // Tim nut co khoa lon nhat tren cay con trai
            root->data = p->data;
            return Delete(root->data, root->left);
        } else { // Co 1 con hoac khong co con
            p = root;
            if (root->left != NULL) // Xu ly neu chi co con trai
                root = root->left;
            else if (root->right != NULL) // Xu ly neu chi co con phai
                root = root->right;
            else
                root = NULL;
            delete p;
        }
    }
    return 1;
}

// Ham duyet cay theo thu tu truoc (NLR)
void preorder(BSTNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Ham duyet cay theo thu tu giua (LNR)
void inorder(BSTNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Ham duyet cay theo thu tu sau (LRN)
void postorder(BSTNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Ham in cay nhi phan ra man hinh
void printTree(BSTNode* root, int space = 0, int height = 10) {
    if (root == NULL) return;
    space += height;
    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data << "\n";
    printTree(root->left, space);
}

// Menu function
void menu() {
    cout << "==============================================================\n";
    cout << "\t\t MENU\n";
    cout << "1. Nhap vao so luong phan tu cua cay\n";
    cout << "2. In cay ra man hinh\n";
    cout << "3. Duyet cay theo thu tu truoc, giua, sau\n";
    cout << "4. Tim mot nut co khoa X trong cay\n";
    cout << "5. In ra man hinh nut co khoa nho nhat va lon nhat trong cay\n";
    cout << "6. Xoa mot nut trong cay\n";
    cout << "7. Thoat\n";
    cout << "==============================================================\n";
}

int main() {
    BSTNode* root = NULL; // Khoi tao cay BST rong
    int choice, value, n, searchValue, deleteValue;
    BSTNode* foundNode, * minNode, * maxNode; // Khai bao ngoai switch
    
    while (true) {
        menu();
        cout << "Chon thao tac: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                // Nhap so luong phan tu cho cay
                cout << "Nhap so luong phan tu cho cay: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "Nhap gia tri thu " << i + 1 << ": ";
                    cin >> value;
                    insert(value, root); // Chen gia tri vao cay
                }
                break;

            case 2:
                // In cay ra man hinh
                cout << "Cay nhi phan: \n";
                printTree(root);  // In cay ra man hinh
                break;
            
            case 3:
                // Duyet cay theo cac thu tu
                cout << "Cac gia tri cua cay duyet truoc (NLR): ";
                preorder(root);
                cout << endl;
                cout << "Cac gia tri cua cay duyet giua (LNR): ";
                inorder(root);
                cout << endl;
                cout << "Cac gia tri cua cay duyet sau (LRN): ";
                postorder(root);
                cout << endl;
                break;
            
            case 4:
                // Tim mot nut co khoa X
                cout << "Nhap gia tri can tim: ";
                cin >> searchValue;
                foundNode = Find(searchValue, root);
                if (foundNode != NULL) {
                    cout << "Tim thay gia tri " << searchValue << " trong cay.\n";
                } else {
                    cout << "Khong tim thay gia tri " << searchValue << " trong cay.\n";
                }
                break;
            
            case 5:
                // Tim nut co khoa nho nhat va lon nhat
                minNode = Findmin(root);
                if (minNode != NULL) {
                    cout << "Gia tri nho nhat trong cay la: " << minNode->data << endl;
                } else {
                    cout << "Cay rong, khong co gia tri nho nhat.\n";
                }
                maxNode = Findmax(root);
                if (maxNode != NULL) {
                    cout << "Gia tri lon nhat trong cay la: " << maxNode->data << endl;
                } else {
                    cout << "Cay rong, khong co gia tri lon nhat.\n";
                }
                break;

            case 6:
                // Xoa mot nut trong cay
                cout << "Nhap gia tri can xoa: ";
                cin >> deleteValue;
                if (Delete(deleteValue, root)) {
                    cout << "Xoa thanh cong. Cay sau khi xoa:\n";
                    printTree(root);
                } else {
                    cout << "Khong tim thay gia tri " << deleteValue << " trong cay.\n";
                }
                break;

            case 7:
                // Thoat
                cout << "Thoat chuong trinh.\n";
                return 0;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    }
    
    return 0;
}

