typedef struct // forma correcta de definir estructura-
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
} Employee;

int menu();

int initEmployees(Employee listado[], int tam); // pone vacio el array

Employee addEmployee(int legajo); // carga 1 empleado.

int buscarLibre(Employee[], int); // buscar el index libre

void mostrarListadoDeEmpleados(Employee listado[], int tam);// recorre el array y muestra empleado por empleado.

void mostrarUnEmpleado (Employee empleadoAmostrar); // le paso 1 empleado, no el array

int cargarListadoDeEmpleados(Employee listado[], int tam,int legajo);

int buscarUnEmployee(Employee listado[], int tam, int legajo);

void bajaEmployee(Employee listado[], int tam);

void modificaEmployee(Employee listado[], int tam);

