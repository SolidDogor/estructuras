/*
 * Problema:
 * Dada una lista enlazada, invertir sus nodos en grupos de tamaño 'k'.
 * Si el último grupo tiene menos de 'k' nodos, debe permanecer intacto.
 * Restricciones:
 * - Memoria O(1) extra. (Prohibido usar pilas, vectores o recursión profunda).
 * - Modificar los nodos "in-place".
 * Estrategia:
 * 1. Enfoque "Two-Pass": Primero calculamos la longitud total para saber exactamente
 * cuántos grupos completos invertiremos (evita lógica compleja de "rollback").
 * 2. Función auxiliar `reverseKGroup`: Invierte un solo bloque y devuelve la nueva cabeza.
 * 3. Lógica de "Pegamento": Usamos un puntero `prev_group_tail` que recuerda dónde terminó
 * el grupo anterior para conectarlo con la cabeza del grupo actual recién invertido.
 * Complejidad:
 * - Tiempo:  O(N) (Recorremos la lista dos veces, sigue siendo lineal).
 * - Espacio: O(1) (Solo punteros auxiliares).
 * =========================================================================================
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * Inversión Local
     * Invierte solo los primeros 'k' nodos a partir de 'head'.
     * Retorna: La nueva cabeza de este subgrupo.
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Validación de seguridad
        if(isKLargerThanHead(head, k)) {
            std::cout << "ERROR: k es mayor que los nodos restantes.\n";
            return nullptr;
        }

        ListNode *prev = nullptr;
        ListNode *current = head;
        ListNode *temp_next = nullptr;
        
        //Lógica estándar de inversión de lista
        while(k > 0 && current != nullptr) {
            temp_next = current->next; //Guardar referencia futura
            current->next = prev;      //Invertir flecha
            prev = current;            //Avanzar prev
            current = temp_next;       //Avanzar current
            k--;
        }

        //Punto crítico: Conexión con el futuro
        //Al terminar el bucle:
        //'head' (que era el primero) ahora es el ÚLTIMO nodo de este grupo invertido.
        //'current' está apuntando al primer nodo del SIGUIENTE grupo (o null).
        //Conectamos para no romper la cadena global:
        head->next = current; 
        
        //'prev' es el nuevo primer nodo de este grupo.
        return prev; 
    }

    //Verifica si hay suficientes nodos para un grupo k
    bool isKLargerThanHead(ListNode* head, int k) {
        int q = 1;
        ListNode* aux = head;
        while(aux) {
            aux = aux->next;
            q++;
        }
        return (q < k);
    }

    //Calcula longitud total (necesario para la estrategia Two-Pass)
    int nodesQuantity(ListNode* head) {
        if(!head) return 0;
        int q = 1;      
        ListNode* aux = head;
        while(aux->next) {
            aux = aux->next;
            q++;
        }
        return q;
    }

    /**
     * Main logic: Orquestador
     * Administra la conexión entre los diferentes grupos invertidos.
     */
    ListNode* reverseKGroups(ListNode* head, int k) {
        if (!head || k <= 1) return head;
        
        //Calcular cuántas inversiones completas haremos.
        //Esto simplifica la lógica de "qué hacer con los sobrantes".
        int groups_to_reverse = nodesQuantity(head) / k;
        
        ListNode* new_global_head = nullptr; 
        ListNode* prev_group_tail = nullptr; //Puntero clave: La cola del grupo anterior
        ListNode* curr_group_head = head;    //El inicio del grupo actual

        while (groups_to_reverse > 0) {
            //Invertir el bloque actual y obtener su nueva cabeza
            ListNode* new_sub_head = reverseKGroup(curr_group_head, k);

            //Si es la primera vuelta, definimos la nueva cabeza de TODA la lista
            if (new_global_head == nullptr) {
                new_global_head = new_sub_head;
            } 
            
            //Conectamos la cola del grupo anterior con la cabeza del grupo actual.
            if (prev_group_tail != nullptr) {
                prev_group_tail->next = new_sub_head;
            }

            //Preparar punteros para la siguiente iteración
            //El nodo que era la cabeza (curr_group_head) ahora es la cola tras invertir.
            //Lo guardamos en 'prev_group_tail' para usarlo de puente en la siguiente vuelta.
            prev_group_tail = curr_group_head;
            
            //Avanzamos al siguiente bloque.
            curr_group_head = prev_group_tail->next; 

            groups_to_reverse--;
        }
        
        return new_global_head; 
    }

    //Utilidad para visualizar
    void printListNode(ListNode* head) {
        ListNode* aux = head;
        while(aux) {
            std::cout << aux->val;
            (aux->next) ? std::cout << " -> " : std::cout << "\n";
            aux = aux->next;
        }
    }

    //Utilidad para insertar
    void insert(ListNode*& head, int val) {
        if(!head) {
            head = new ListNode(val);
        } else {
            ListNode* aux = head;
            while(aux->next) aux = aux->next;
            aux->next = new ListNode(val);
        }
    }
};

int main() {
    Solution solution;
    ListNode *head = nullptr;
    int k = 2;
    int n = 7;
    
    //Setup del test case
    for(int i = 1; i <= n; ++i) solution.insert(head, i);
    
    std::cout << "Original:\n";
    solution.printListNode(head);

    std::cout << "Invertido k = " << k << ":\n";
    head = solution.reverseKGroups(head, k);

    solution.printListNode(head);
    
    //TODO para producción: Implementar destructor o función freeList() para evitar Memory Leaks.
    
    return 0;
}