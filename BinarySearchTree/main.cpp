#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int deger;
    Node* left;
    Node* right;

    Node(int deger)
    {
        this->deger = deger;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree
{
public:
    Node* root;
    int toplam;
    int count;
    int leafssss;
    int ortalama;
    BinarySearchTree() {
        root = NULL;
        toplam=0;
        count=0;
        leafssss=0;
        ortalama=0;
    }
    ~BinarySearchTree() {
        deleteAllNodes(root);
    }
    void deleteAllNodes(Node* node)
    {
        if (node == NULL) return;
        if (node->left != NULL)
        {
            deleteAllNodes(node->left);
        }
        if (node->right != NULL)
        {
            deleteAllNodes(node->right);
        }
        delete node;
    }
    bool insertNode(int deger)
    {
        Node* node = new Node(deger);
        if (root == NULL)
        {
            root = node;
            count++;
            return true;
        }
        Node* tmp = root;
        while (true)
        {
            if (node->deger == tmp->deger)
            {
                cout << "Mukerrer node eklenmeye calisiliyor!\n";
                return false;
            }
            if (node->deger < tmp->deger)
            {
                if (tmp->left == NULL)
                {
                    tmp->left = node;
                    count++;
                    return true;
                }
                tmp = tmp->left;
            }
            else {
                if (tmp->right == NULL)
                {
                    tmp->right = node;
                    count++;
                    return true;
                }
                tmp = tmp->right;
            }

        }
    }
    void DFSPreOrderSearchPrintAllNodes(Node* node)
    {
        cout << node->deger << " , ";
        if (node->left != NULL)
        {
            DFSPreOrderSearchPrintAllNodes(node->left);
        }
        if (node->right != NULL)
        {
            DFSPreOrderSearchPrintAllNodes(node->right);
        }
    }
    void leafcount(Node* node)
    {
        if (node->left != NULL)
        {
            leafcount(node->left);
        }
        if (node->right != NULL)
        {
            leafcount(node->right);
        }
        if(node->right==NULL && node->left==NULL)
        {
            leafssss= leafssss + node->deger;
        }

    }
    Node* DFSPreOrderSearchAra(Node* node, int arananDeger)
    {
        if (node == NULL || node->deger == arananDeger)
        {
            return node;
        }

        if (arananDeger < node->deger)
        {
            return DFSPreOrderSearchAra(node->left, arananDeger);
        }
        else {
            return DFSPreOrderSearchAra(node->right, arananDeger);
        }
    }
    void DFSPostOrderSearchPrintAllNodes(Node* node)
    {
        if (node->left != NULL)
        {
            DFSPostOrderSearchPrintAllNodes(node->left);
        }
        if (node->right != NULL)
        {
            DFSPostOrderSearchPrintAllNodes(node->right);
        }
        cout << node->deger << " , ";
    }
    void DFSInOrderSearchPrintAllNodes(Node* node)
    {
        if (node->left != NULL)
        {
            DFSInOrderSearchPrintAllNodes(node->left);
        }
        cout << node->deger << " , ";
        if (node->right != NULL)
        {
            DFSInOrderSearchPrintAllNodes(node->right);
        }
    }
    void BreadthFirstSearch()
    {
        queue<Node*> queue1;
        queue1.push(root);

        while(queue1.size() > 0)
        {
            Node* node = queue1.front();
            queue1.pop();
            cout<<node->deger<<" , ";

            if(node->left != NULL)
            {
                queue1.push(node->left);
            }
            if(node->right != NULL)
            {
                queue1.push(node->right);
            }
        }
    }
    void getcount()
    {
        cout<<"agaçtaki elaman sayısı: "<<count<<endl;
    }
    Node* search(Node* root, int deger) {

        if (root == NULL || root->deger == deger)
            return root;


        if (deger < root->deger)
            return search(root->left, deger);


        return search(root->right, deger);
    }
    Node* deleteRec(Node* root, int deger) {
        // Base case: Eğer ağaç boşsa
        if (root == nullptr)
            return root;

        // Eğer silinecek değer mevcut kök düğümün değerinden küçükse,
        // sol alt ağaçta ara
        if (deger < root->deger) {
            root->left = deleteRec(root->left, deger);
        }
            // Eğer silinecek değer mevcut kök düğümün değerinden büyükse,
            // sağ alt ağaçta ara
        else if (deger > root->deger) {
            root->right = deleteRec(root->right, deger);
        }
            // Değer kök düğümün değerine eşitse, bu düğüm silinecek düğümdür
        else {
            // Düğümün yalnızca bir çocuğu veya hiç çocuğu yoksa
            if (root->left == nullptr) {
                Node* temp = root->right; // Sağ alt ağacı geçici bir değişkene ata
                delete root;              // Mevcut düğümü sil
                return temp;              // Sağ alt ağacı geri döndür
            } else if (root->right == nullptr) {
                Node* temp = root->left;  // Sol alt ağacı geçici bir değişkene ata
                delete root;              // Mevcut düğümü sil
                return temp;              // Sol alt ağacı geri döndür
            }

            // Düğümün iki çocuğu varsa
            // Sağ alt ağaçtaki en küçük değere sahip düğümü bul
            Node* temp = findMin(root->right);

            // Mevcut düğümün değerini bu düğümün değeri ile değiştir
            root->deger = temp->deger;

            // Bu düğümü sil
            root->right = deleteRec(root->right, temp->deger);
        }
        return root;
    }
    Node* findMin(Node* root)
    {
        if (root->left == nullptr)
        {
            return root;
        }
        return findMin(root->left); //
    }
    int maxdeep(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            int leftdeep = maxdeep(node->left);
            int rightdeep = maxdeep(node->right);

            if (leftdeep < rightdeep) {
                return rightdeep + 1;
            } else {
                return leftdeep + 1;
            }
        }
    }
    int yukseklik(Node*Node){
        if(Node!=NULL){
            return 1+max(yukseklik(Node->left),yukseklik(Node->right));
        }
        return 0;
    }
    void deleteleaf(int deger,int parents)
    {
        Node* parentss = search(root,parents);
        Node* leaf = search(root,deger);
        if (deger<parents)
        {
            parentss->left = NULL;
            delete leaf;
        }
        else
        {
            parentss->right= NULL;
            delete leaf;
        }
    }
    void toplamm()
    {
        queue<Node*> queue1;
        queue1.push(root);

        while(queue1.size() > 0)
        {
            Node* node = queue1.front();
            queue1.pop();
            toplam = toplam + node->deger;

            if(node->left != NULL)
            {
                queue1.push(node->left);
            }
            if(node->right != NULL)
            {
                queue1.push(node->right);
            }
        }
        cout<<toplam;

    }
    Node* deleteNode(Node* root, int deger)
    {
        if (deger < root->deger) root->left = deleteNode(root->left, deger);
        else if (deger> root->deger) root->right = deleteNode(root->right, deger);
        else
        {
            if (!root->left)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->deger = temp->deger;
            root->right = deleteNode(root->right, temp->deger);
        }
        return root;
    }

    bool isBalanced(Node* root) {
        if (root == nullptr) return true; // Boş ağaç dengelidir

        int leftHeight = maxdeep(root->left);
        int rightHeight = maxdeep(root->right);

        if (abs(leftHeight - rightHeight) > 1) return false; // Yükseklik farkı 1'den büyükse dengeli değil

        return isBalanced(root->left) && isBalanced(root->right); // Alt ağaçların dengeli olup olmadığını kontrol et
    }





};


int main()
{
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insertNode(52);
    bst->insertNode(27);
    bst->insertNode(15);
    bst->insertNode(30);
    bst->insertNode(78);
    bst->insertNode(65);
    bst->insertNode(14);
    bst->insertNode(17);
    bst->insertNode(28);
    bst->insertNode(31);
    bst->insertNode(53);
    bst->insertNode(66);
    bst->insertNode(79);
    bst->insertNode(82);
    cout<<bst->isBalanced(bst->root);








    delete bst;
}
