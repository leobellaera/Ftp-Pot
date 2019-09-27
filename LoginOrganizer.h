//
// Created by leobellaera on 26/9/19.
//

#ifndef TP_LOGINORGANIZER_H
#define TP_LOGINORGANIZER_H

#include <string>

class LoginOrganizer {
    private:
        std::string user;
        std::string pw;
    public:
        bool LoginOrganizer::passwordIsCorrect(std::string password) {
            if (password != pw) {
                return false;
            }
        }


};


/* clients_already_logged (map)
 * clients_logged_recently_without_pass(map key value: none)
 *
 *
 * insertUser(int client, string user)
 *      if client in clients_already_logged
 *          return message_already_logged
 *      else clients_logged_recently_without_pass.add(client)
 *
 *
 * insertPass(int client, string pass) {
 *      if client in clients_already_logged
 *          return message_already_logged
 *      else if client in clients_logged_recently_without_pass && key == user && pass == pw
 *            clients_already_logged.add(client)
 *            return message_logged
 *      else
 *            return message_error
 *
 *
 * aclaracion: desde afuera de la funcion, siempre que se realice un comando distinto de insertar user o pass
 * se debe ver si el cliente esta en el map de clientes logeados recientemente sin pass, si esta, se debe eliminar
 * (asi nos aseguramos q el chaboncito siempre primero ponga el user y despues la pw)

*/
#endif //TP_LOGINORGANIZER_H
