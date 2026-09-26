#include <iostream>
#include <chrono>
#include <vector>
#include "liste.hpp"
#include "liste_item.hpp"
#include "liste_it.hpp"

int main()
{
    Liste liste1 = Liste();
    liste1.add(4);
    liste1.add(7);
    liste1.add(10);

    liste1.print();

    std::cout << liste1.get(2) << std::endl;

    std::cout << "la taille de la liste est : " << liste1.size() << std::endl;

    liste1.clear();
    liste1.print();

    Liste liste2 = Liste();
    liste2.add(4);
    liste2.add(7);
    liste2.add(10);

    Liste_it liste_it1 = Liste_it(liste2);
    std::cout << "La liste peut etre itere : " << liste_it1.hasNext() << std::endl;

    liste2.print();

    int *valeur_pointeur = liste_it1.next();
    int valeur = *valeur_pointeur;
    std::cout << "J'utilise premier methode next : " << valeur << std::endl;

    valeur_pointeur = liste_it1.next();
    valeur = *valeur_pointeur;
    std::cout << "J'utilise deuxieme methode next : " << valeur << std::endl;


    
    const int N = 20000; // 20 000 éléments pour mettre en évidence les écarts sans bloquer

    std::cout << "=== 1. TEST D'INSERTION (" << N << " elements) ===" << std::endl;

    // A. Ajout dans notre Liste (add() en fin de liste)
    Liste ma_liste;
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i)
    {
        ma_liste.add(i);
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto d_add_custom = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Temps add() Liste perso : " << d_add_custom << " ms" << std::endl;

    // B. Ajout dans std::vector (push_back)
    std::vector<int> vec;
    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i)
    {
        vec.push_back(i);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto d_add_vec = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Temps push_back() std::vector : " << d_add_vec << " ms\n" << std::endl;


    std::cout << "=== 2. TEST DE PARCOURS (" << N << " elements) ===" << std::endl;

    // A. Parcours classique par get(i)
    long long somme_get = 0;
    t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < ma_liste.size(); ++i)
    {
        somme_get += ma_liste.get(i);
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto d_parcours_get = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Parcours par get(i)      : " << d_parcours_get << " ms (Somme: " << somme_get << ")" << std::endl;

    // B. Parcours avec Liste_it
    long long somme_it = 0;
    t1 = std::chrono::high_resolution_clock::now();
    Liste_it it(ma_liste);
    while (it.hasNext())
    {
        int* v = it.next();
        if (v) somme_it += *v;
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto d_parcours_it = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Parcours avec Liste_it   : " << d_parcours_it << " ms (Somme: " << somme_it << ")" << std::endl;

    // C. Parcours STL std::vector (itérateur)
    long long somme_stl = 0;
    t1 = std::chrono::high_resolution_clock::now();
    for (auto val : vec)
    {
        somme_stl += val;
    }
    t2 = std::chrono::high_resolution_clock::now();
    auto d_parcours_vec = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Parcours STL vector      : " << d_parcours_vec << " ms (Somme: " << somme_stl << ")" << std::endl;

    return 0;
}