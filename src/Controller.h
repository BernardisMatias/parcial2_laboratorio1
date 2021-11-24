int controller_sortBooks(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);
int controller_calculateId(LinkedList* pArrayListBook);
int controller_ListBooks(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);
int controller_addBook(LinkedList* pArrayListBook);

int controller_saveBooksAsText(char* path , LinkedList* pArrayListBook);
int controller_saveLastBookAsText(char* path, int id);

int controller_loadLastBookIdFromText(char* path);
int controller_loadBooksFromFile(LinkedList* pArrayListBook, char* fileName);
int controller_loadBooksFromText(char* path , LinkedList* pArrayListBook);

int controller_loadEditorialsFromText(char* path , LinkedList* pArrayListEditorial);
int controller_loadEditorialsFromFile(LinkedList* listaEditoriales, char* fileName);

int controller_listBooksFromEditorialMinotauro(LinkedList* bookList, LinkedList* pArrayEditorial);
