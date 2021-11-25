
int controller_saveBooksAsText(char* path , LinkedList* pArrayListBook);
int controller_saveLastBookAsText(char* path, int id);

int controller_sortBooks(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);
int controller_obtenerLibroId(LinkedList* pArrayListBook);
int controller_listLibros(LinkedList* pArrayListBook, LinkedList* pArrayListEditorial);
int controller_addLibro(LinkedList* pArrayListBook);
int controller_loadLastBookIdFromText(char* path);
int controller_loadLibrosFromFile(LinkedList* pArrayListBook, char* fileName);
int controller_loadLibrosFromText(char* path , LinkedList* pArrayListBook);

int controller_loadEditorialsFromText(char* path , LinkedList* pArrayListEditorial);
int controller_loadEditorialsFromFile(LinkedList* listaEditoriales, char* fileName);

int controller_listarLibrosMinotauro(LinkedList* listaLibros, LinkedList* pArrayEditorial);
int controller_aplicarDescuento(LinkedList* listaLibros, LinkedList* pArrayEditorial);
