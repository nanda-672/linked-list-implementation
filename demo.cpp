#include <iostream>
using namespace std;
  
class Node {
public:
    int data;
    Node* next;
};

// fungsi untuk mencetak linked list mulai dari head sampai tail/node terakhir
void printlist(Node *node){
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}

Node* copylist(Node *node){

    Node* current = node;

    Node* copy = new Node;
    copy->data = current->data;
    copy->next = NULL;

    Node* const head = copy;

    current = current->next; // memajukan current karena head sudah di copy

    while (current != NULL) {
       // mengalokasikan memori untuk node selanjutnya
       copy = copy->next = new Node;

       // mengcopy data dari node pada linked list asli
       copy->data = current->data;

       // link ke node selanjutnya
       copy->next = NULL;

       // memajukan current
       current = current->next;
    }

    // mereturn pointer ke elemen pertama
    return head;
}

// fungsi menghapus list
void deletelist(Node** head_ref){
 
    // menuju head
    Node* current = *head_ref;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    *head_ref = NULL;
}

// fungsi untuk menghapus/dealokasi memori pada linked list
void deletenode(Node** head_ref, int key){
     
    // store node head
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // mengecek apakah key ada pada node pertama/head
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;            // dealokasi memori
        return;
    }
    else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // kasus jika yang ingin kita hapus tidak ada pada linked list tersebut
    if (temp == NULL) {
        return;
    }
    // unlink node dari linked list
    prev->next = temp->next;
 
    // dealokasi memori
    delete temp;
    }
}

// fungsi menambahkan node di depan
void push(Node** head_ref, int new_data){
    // membuat node baru
    Node* new_node = new Node();
 
    // mengisi data pada node tersebut
    new_node->data = new_data;
 
    // membuat next dari new_node sebagai head
    new_node->next = (*head_ref);
 
    // memindahkan head sehingga menuju ke new_node
    (*head_ref) = new_node;
}

// fungsi menambahkan node di belakang
void append(Node** head_ref, int new_data){
    // membuat node baru
    Node* new_node = new Node();
 
    Node *last = *head_ref;
 
    // mengisi data pada node tersebut
    new_node->data = new_data;
 
    // karena dibelakang berarti next menjadi NULL
    new_node->next = NULL;
 
    // kasus untuk linked list yang kosong
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
 
    // menuju ke node akhir
    while (last->next != NULL)
        last = last->next;
 
    //mengubah next dari node akhir
    last->next = new_node;
    return;
}

// fungsi remove node head
Node* removefirstnode(Node* head){
    // kasus ketika list kosong
    if (head == NULL){
        return NULL;
    }
    // memindah pointer head ke node selanjutnya
    Node* temp = head;
    head = head->next;
 
    delete temp;
 
    return head;
}

// fungsi remove node tail
Node* removelastnode(Node* head){
    // kasus ketika list kosong
    if (head == NULL){
        return NULL;
    }
    if (head->next == NULL) {
        delete head; // delete node
        return NULL;
    }
 
    // menemukan node sebelum node akhir
    Node* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
 
    // delete node akhir
    delete (second_last->next);
 
    // mengubah next menjadi null sehingga node sebelum akhir menjadi node akhir
    second_last->next = NULL;
 
    return head;
}

int listsize(Node* head){
    int jml = 0; // deklarasi variabel hitung serta assign nilai minimum (0)
    Node* current = head;
    while (current != NULL){ // pengecekan hingga sampai tidak ada node lagi setelahnya
        jml++; // penambahan variabel hitung
        current = current->next;
    }
    return jml;
}

// fungsi return alamat node yang memiliki nilai tertentu
Node* search(Node* head, int x){
    Node* current = head;
    while (current != NULL){ // mengulang pengecekan hingga tail atau berhenti saat list kosong
        if (current->data == x) // pengecekan data/nilai yang bersesuaian
            return current;
        current = current->next;
    }
    return 0;
}

// fungsi untuk mengecek apakah suatu node bagian dari linked list
bool searchnode(Node* head, Node* ref){
    Node* current = head;
    while (current != NULL){ // mengulang pengecekan hingga tail atau berhenti saat list kosong
        if (current == ref) // pengecekan node yang bersesuaian
            return true;
        current = current->next;
    }
    return false;
}

int searchbig(Node* head){
    Node* current = head;
    int ref = current->data;
    while (current != NULL){ // mengulang pengecekan hingga tail atau berhenti saat list kosong
        if ((current->data) > ref) // pengecekan data/nilai yang bersesuaian
            ref = current->data;
        current = current->next;
    }
    return ref;
}

int searchsmall(Node* head){
    Node* current = head;
    int ref = current->data;
    while (current != NULL){ // mengulang pengecekan hingga tail atau berhenti saat list kosong
        if ((current->data) < ref) // pengecekan data/nilai yang bersesuaian
            ref = current->data;
        current = current->next;
    }
    return ref;
}

// fungsi untuk melakukan inverse pada linked list
void inverse(Node **head_ref) {
    Node* next = NULL;
    Node* prev = NULL;
    Node* current = (*head_ref);
    while(current != NULL) { // iterasi
        next = current->next; // menyimpan node next
        current->next = prev; // mengubah next dari node saat ini

        // memundurkan prev dan current 
        prev = current; 
        current = next;
    }
    (*head_ref) = prev; // node akhir kini menjadi head (sudah ter inverse)
}

// fungsi untuk menjalankan operasi concat (mengubah linked list awal)
void concat(Node* node1, Node* node2) {
    if (node1 != NULL && node2 != NULL){
        if (node1->next == NULL)
            node1->next = node2; // agar tercapai hasil akhir node1->tail->next = node2->head
        else
            concat(node1->next, node2); // mengulang fungsi (rekursif)
    }
    else
        cout << "terdapat linked list kosong";
}

int main(){
    Node* head = NULL;
    Node* kedua = NULL;
    Node* ketiga = NULL;
    int x;
  
    head = new Node();
    kedua = new Node();
    ketiga = new Node();
  
  
    head->data = 1; // assign data ke node pertama/head
    head->next = kedua; // Link node pertama dengan node kedua
  
    kedua->data = 2; // assign data ke node kedua
    kedua->next = ketiga; // link node kedua dengan node ketiga
  
    ketiga->data = 3; // assign data ke node ketiga
    ketiga->next = NULL;

    cout << "linked list :\n";
    printlist(head); // mencetak linked list

    x = 2;
    deletenode(&head, x); // menghapus elemen pada linked list
    cout << "\nlinked list setelah 2 dihapus :\n";
    printlist(head);

    push(&head, 7); // menambahkan 7 ke depan linked list
    push(&head, 5); // menambahkan 5 ke depan linked list
    append(&head, 4); // menambahkan 4 ke belakang linked list
    append(&head, 2); // menambahkan 4 ke belakang linked list
    cout << "\nlinked list setelah penambahan :\n";
    printlist(head);

    head = removefirstnode(head); // menghapus node depan/head
    head = removefirstnode(head); // menghapus node belakang/tail
    cout << "\nlinked list setelah pengurangan :\n";
    printlist(head);

    // cek ukuran dari linked list
    cout << "\nukuran linked list kita sekarang adalah : " << listsize(head) << endl;

    // cek alamat node yang berisi suatu nilai
    cout << "\nalamat dari node yang berisi nilai 3 : ";
    if (search(head, 3) == 0)
        cout << "tidak ada nilai tersebut\n";
    else
        cout << search(head, 3) << endl;

    cout << "\nalamat dari node yang berisi nilai 5 : ";
    if (search(head, 5) == 0)
        cout << "tidak ada nilai tersebut\n";
    else
        cout << search(head, 5) << endl;

    cout << "\npengecekan node dengan alamat " << search(head, 3) << " : ";
    if (searchnode(head, search(head, 3)))
        cout << "node ada pada linked list ini\n";
    else
        cout << "tidak ditemukan node yang bersangkutan pada linked list ini\n";

    // memunculkan nilai terbesar dan terkecil pada linked list
    cout << "\nnilai terbesar pada linked list : " << searchbig(head) << endl;
    cout << "\nnilai terkecil pada linked list : " << searchsmall(head) << endl;

    // melakukan inverse dari linked list awal
    cout << "\nlinked list setelah di inverse :\n";
    inverse(&head);
    printlist(head);

    // linked list kosong
    Node* newhead = NULL;
    newhead = copylist(head); // mengcopy linked list yang ada

    // menjalankan operasi concat
    cout << "\n hasil operasi concat : \n";
    concat(head, newhead);
    printlist(head); // mencetak linked list hasil concat

    return 0;
}