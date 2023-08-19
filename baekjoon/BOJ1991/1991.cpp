#include <iostream>
#include <memory>
#include <functional>

using namespace std;

struct Node {
    char data;
    unique_ptr<Node> left;
    unique_ptr<Node> right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

unique_ptr<Node> root;

void insert(char data, char l_data, char r_data) {
    if (!root) {
        root = make_unique<Node>(data);
        if (l_data != '.') root->left = make_unique<Node>(l_data);
        if (r_data != '.') root->right = make_unique<Node>(r_data);
        return;
    }

    function<void(unique_ptr<Node>&)> searchAndInsert = [&](unique_ptr<Node>& node) {
        if (!node) return;
        if (node->data == data) {
            if (l_data != '.' && !node->left) node->left = make_unique<Node>(l_data);
            if (r_data != '.' && !node->right) node->right = make_unique<Node>(r_data);
        } else {
            searchAndInsert(node->left);
            searchAndInsert(node->right);
        }
    };

    searchAndInsert(root);
}

void preOrder(const unique_ptr<Node>& node) {
    if (!node) return;
    cout << node->data;
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(const unique_ptr<Node>& node) {
    if (!node) return;
    inOrder(node->left);
    cout << node->data;
    inOrder(node->right);
}

void postOrder(const unique_ptr<Node>& node) {
    if (!node) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char k, l, r;
        cin >> k >> l >> r;
        insert(k, l, r);
    }

    preOrder(root); cout << "\n";
    inOrder(root); cout << "\n";
    postOrder(root); cout << "\n";

    return 0;
}
