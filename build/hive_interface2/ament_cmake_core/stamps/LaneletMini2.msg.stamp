# ============================================================
# Hive Robotics - LaneletMini2.msg
# ============================================================
# Représente une portion de voie simplifiée issue de la base SQL lanelet_mini2
# Utilisée pour la navigation autonome dans Hive Robotics.
# Chaque champ correspond directement à une colonne SQL.
# ============================================================

# --- Identifiants hiérarchiques ---
string enterprise_full_id_str           # Entreprise associée (nom complet)
string deployment_full_id_str           # Déploiement associé (nom complet)
string slam_session_full_id_str         # Session SLAM associée (nom complet)

# --- Identifiant principal du lanelet ---
int32 lanelet_mini_id                   # ID unique du lanelet_mini

# --- Coordonnées du point de départ (référentiel 'map') ---
float32 start_point_x
float32 start_point_y
float32 start_point_z

# --- Coordonnées du point d'arrivée (référentiel 'map') ---
float32 end_point_x
float32 end_point_y
float32 end_point_z

# --- Propriétés de navigation ---
int32 navigation_direction              # 0=fermé | 1=start->end | 2=end->start | 3=bidirectionnel
int32 border_mode                       # 0=aucun | 1=gauche | 2=droite | 3=deux côtés
bool u_turn_allowed                     # true = demi-tour autorisé
bool slope_alert                        # true = pente significative (précaution requise)
bool vegetation_alert                   # true = forte végétation (ralentir)
bool offroad_alert                      # true = zone non-bitumée (terre, gravier, etc.)

# --- Groupes logiques ---
string configuration_group_id_str       # Sous-groupe de configuration (ex: avenues)
string road_group_id_str                # Groupe routier (ex: grande route)

# --- Propriétés physiques ---
int32 max_speed                         # Vitesse max (en km/h)
float32 width                           # Largeur de la route (en mètres)
