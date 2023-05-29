# Pipex
Ce projet consiste à gérer des pipes.

Fonctions autorisées dans le projet :

| Fonction | Définition | Prototype | Bibliothèque |
| --- | --- | --- | --- |
| open | Ouvre un fichier | int open(const char *pathname, int flags); | `<fcntl.h>` ou `<sys/types.h>` |
| close | Ferme un fichier | int close(int fd); | `<unistd.h>` |
| read | Lit des données à partir d'un fichier | ssize_t read(int fd, void *buf, size_t count); | `<unistd.h>` |
| write | Écrit des données dans un fichier | ssize_t write(int fd, const void *buf, size_t count); | `<unistd.h>` |
| malloc | Alloue de la mémoire dynamiquement | void *malloc(size_t size); | `<stdlib.h>` |
| free | Libère de la mémoire allouée dynamiquement | void free(void *ptr); | `<stdlib.h>` |
| perror | Affiche un message d'erreur associé au code d'erreur actuel | void perror(const char *s); | `<stdio.h>` |
| strerror | Récupère une chaîne de caractères décrivant le code d'erreur donné | char *strerror(int errnum); | `<string.h>` |
| access | Vérifie les droits d'accès à un fichier | int access(const char *pathname, int mode); | `<unistd.h>` |
| dup | Duplique un descripteur de fichier | int dup(int oldfd); | `<unistd.h>` |
| dup2 | Duplique un descripteur de fichier avec un nouveau descripteur spécifié | int dup2(int oldfd, int newfd); | `<unistd.h>` |
| execve | Exécute un programme à partir du fichier exécutable | int execve(const char *pathname, char *const argv[], char *const envp[]); | `<unistd.h>` |
| exit | Termine le processus en cours | void exit(int status); | `<stdlib.h>` |
| fork | Crée un nouveau processus en copiant le processus existant | pid_t fork(void); | `<unistd.h>` |
| pipe | Crée une paire de descripteurs de fichiers pour une communication unidirectionnelle | int pipe(int pipefd[2]); | `<unistd.h>` |
| unlink | Supprime un fichier du système de fichiers | int unlink(const char *pathname); | `<unistd.h>` |
| wait | Attend la fin du processus fils | pid_t wait(int *status); | `<sys/wait.h>` |
| waitpid | Attend la fin d'un processus fils spécifique | pid_t waitpid(pid_t pid, int *status, int options); | `<sys/wait.h>` |

Notez que certaines fonctions appartiennent à plusieurs bibliothèques, donc les bibliothèques mentionnées dans le tableau ne sont pas exclusives. Assurez-vous d'inclure les bibliothèques appropriées dans votre programme en fonction des fonctions que vous utilisez.
