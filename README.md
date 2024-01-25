# Linked List
linked list adalah struktur data linear dengan elemen-elemen nya dihubungkan menggunakan pointer. Linked list dapat dikatakan menyerupai array, namun dengan kelebihan tersendiri, yakni:
* ukuran yang dinamis (dynamic size)
* penambahan dan pengurangan elemen yang lebih mudah

Sebuah linked list dapat digambarkan sebagai node yang berisi data dan pointer yang menuju ke node selanjutnya sehingga bertindak selayaknya struktur data linear.

## Basic Linked List
Pada C++ kita bisa menginisiasi linked list dengan cara seperti berikut,
```
class Node {
public:
    int data;
    Node* next; //untuk menghubungkan dengan node lain
};
```
sebagai contoh, misalkan kita ingin membuat linked list dengan tiga node, kita beri nama _head_ sebagai node pertama, serta _kedua_ dan _ketiga_ sebagai node dengan urutan yang bersesuaian. Maka kita dapat membuat linked list sehingga menjadi:
```
int main()
{
    Node* head = NULL;
    Node* kedua = NULL;
    Node* ketiga = NULL;
    
    // alokasi memori
    head = new Node();
    kedua = new Node();
    ketiga = new Node();
}
```
setelah itu kita dapat mengassign nilai dari tiap node tersebut dengan cara:
```
int main()
{
    Node* head = NULL;
    Node* kedua = NULL;
    Node* ketiga = NULL;
  
    head = new Node();
    kedua = new Node();
    ketiga = new Node();
  
  
    head->data = 1; // assign data ke node pertama/head
    head->next = kedua; // Link node pertama dengan node kedua
  
    kedua->data = 2; // assign data ke node kedua
    kedua->next = ketiga; // link node kedua dengan node ketiga
  
    ketiga->data = 3; // assign data ke node ketiga
    ketiga->next = NULL;
  
    return 0;
}
```
terlebih jika kita ingin mencetak linked list ini ke layar kita dapat membuat fungsi untuk mencetak linked list secara keseluruhan,
```
// fungsi untuk mencetak linked list mulai dari head sampai tail/node terakhir
void printlist(Node *node)
{
    while (node != NULL)
    {
        cout<<" "<<node->data;
        node = node->next;
    }
}
```
sehingga pada akhir program sebelumnya dapat digunakan fungsi printlist ini,
```
printlist(head);
```
Selain itu, kita juga bisa mengcopy linked list yang kita punya dengan mengalokasikan memori baru, syntaxnya adalah sebagai berikut,
```
Node* copylist(Node *node){

    Node* current = node;

    Node* copy = new Node;
    copy->data = current->data;
    copy->next = NULL;

    Node* const head = copy;

    current = current->next;

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
```
kita juga bisa menghapus/dealokasi memori dari bagian linked list yang sudah kita buat entah itu seluruh ataupun sebagian, caranya adalah sebagai berikut,
```
void deleteList(Node** head_ref)
{
 
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
```
berikut adalah fungsi untuk menghapus/dealokasi memori dari elemen linked list,
```
void deletenode(Node** head_ref, int key)
{
     
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
```
## Manipulasi Linked List

dengan menggunakan konsep dari pointer kita bisa melakukan beberapa manipulasi terhadap linked list yang kita miliki seperti menambahkan node didepan (push) maupun dibelakang (append) linked list. Cara untuk menambahkan node didepan linked list adalah sebagai berikut,
```
void push(Node** head_ref, int new_data)
{
    // membuat node baru
    Node* new_node = new Node();
 
    // mengisi data pada node tersebut
    new_node->data = new_data;
 
    // membuat next dari new_node sebagai head
    new_node->next = (*head_ref);
 
    // memindahkan head sehingga menuju ke new_node
    (*head_ref) = new_node;
}
```
sedangkan untuk kasus menambahkan node di belakang linked list menjadi,
```
void append(Node** head_ref, int new_data)
{
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
 
    /mengubah next dari node akhir
    last->next = new_node;
    return;
}
```

selain menambahkan node kita juga bisa memanipulasi kebalikannya, yakni menghilangkan node entah itu diawal ataupun diakhir, caranya adalah sebagai berikut,
```
Node* removeFirstNode(Node* head)
{
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
```
```
Node* removeLastNode(Node* head)
{
    // kasus ketika list kosong
    if (head == NULL){
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
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
```


Selain melakukan penambahan dan pengurangan kita juga bisa melakukan analisis terhadap atribut dari suatu linked list, seperti jumlah node pada suatu linked list, nilai terbesar dan terkecil yang ada pada suatu linked list, alamat dari suatu node, dan lain lain. Untuk mengetahui jumlah node/ ukuran list dari suatu linked list kita dapat menggunakan fungsi untuk berpindah dari node awal hingga ke node akhir dimana tidak ada node lagi setelahnya. fungsinya adalah sebagai berikut:
```
int listsize(Node* head){
    int jml = 0; // deklarasi variabel hitung serta assign nilai minimum (0)
    Node* current = head;
    while (current != NULL){ // pengecekan hingga sampai tidak ada node lagi setelahnya
        jml++; // penambahan variabel hitung
        current = current->next;
    }
    return jml;
```
pengecekan terhadap suatu nilai pada suatu linked list dan mereturn alamat dari node yang bersangkutan. Hal tersebut dapat dilakukan dengan cara menggunakan fungsi:
```
Node* search(Node* head, int x){
    Node* current = head;
    while (current != NULL){ // pengecekan hingga tail
        if (current->data == x) // pengecekan data/nilai yang bersesuaian
            return current;
        current = current->next;
    }
    return 0;
}
```
ada juga pengecekan keberadaan node dalam suatu linked list, yakni dengan cara memastikan alamat nya bersesuaian:
```
bool searchnode(Node* head, Node* ref){
    Node* current = head;
    while (current != NULL){ // mengulang pengecekan hingga tail atau berhenti saat list kosong
        if (current == ref) // pengecekan node yang bersesuaian
            return true;
        current = current->next;
    }
    return false;
}
```

Pada linked list kita juga bisa melakukan operasi inverse pada linked list yang kita miliki. Misalkan dari 1 2 3 4 menjadi 4 3 2 1. Hal ini dapat dilakukan memanipulasi linked list yang kita miliki sehingga "arahnya berubah". dalam C++ fungsi nya dapat dituliskan menjadi,
```
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
```
Terakhir, kita juga dapat mengimplementasikan concat pada linked list yang kita miliki. contoh concat itu sendiri, misalkan kita mempunyai 2 linked list 1 2 3 dan 4 5 6, maka concatnya menjadi 1 2 3 4 5 6. caranya adalah sebagai berikut,
```
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
```

## Reference
1. [Singly Linked List](https://www.geeksforgeeks.org/data-structures/linked-list/singly-linked-list/). _GeeksforGeeks_. Retrieved 25 May 2021.



