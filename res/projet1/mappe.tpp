/**
 * @file mappe.tpp
 * @author C. Jermann
 * @since 05/02/2015
 * @brief Implémentation de la classe Mappe<K,V>
 * 
 * @b Note s'agissant d'un patron de classe, ce fichier est inclus dans mappe.hpp
**/

//------------------------------------------------------------------------------
template <typename K, typename V>
Mappe<K,V>::Mappe()
{
   // rien à faire
}

//------------------------------------------------------------------------------
template <typename K, typename V>
Mappe<K,V>::~Mappe()
{
   // rien à faire
}

//------------------------------------------------------------------------------
template <typename K, typename V>
void Mappe<K,V>::associer(K clf, V valr)
{
   contenu[clf]=valr;
}

//------------------------------------------------------------------------------
template <typename K, typename V>
bool Mappe<K,V>::estVide() const
{
   return contenu.empty();
}

//------------------------------------------------------------------------------
template <typename K, typename V>
V Mappe<K,V>::valeurAssociee(K clf) const
{
   return contenu.at(clf); // émet une erreur si la clef n'est pas présente
}

//------------------------------------------------------------------------------
template <typename K, typename V>
void Mappe<K,V>::dissocier(K clf)
{
   contenu.erase(clf);
}

//------------------------------------------------------------------------------
template <typename K, typename V>
bool Mappe<K,V>::estClef(K clf) const
{
   return contenu.count(clf)==1;
}

//------------------------------------------------------------------------------
template <typename K, typename V>
std::vector<K> Mappe<K,V>::trousseau() const
{
   std::vector<K> clefs;
   for (auto couple : contenu)
   {
      clefs.push_back(couple.first);
   }
   return clefs;
}
