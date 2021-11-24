#ifndef PARSER_H_
#define PARSER_H_
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListBook);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);
int parser_OneEditorialFromText(FILE* pFile);
int parser_OneBookFromText(FILE* pFile);
#endif
