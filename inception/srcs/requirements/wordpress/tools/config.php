<?php
define('DB_NAME', 'mariadb_db'); // The name of the database for WordPress
define('DB_USER', 'pclaus');      // Your database username
define('DB_PASSWORD', 'pclaus');  // Your database password
define('DB_HOST', 'mariadb');     // The hostname of your MariaDB container (service name from Docker Compose)
define('DB_CHARSET', 'utf8mb4');  // Database charset
define('DB_COLLATE', '');         // Database collation (empty is default)

// ** WordPress site and home URL (Important for Nginx and SSL)** //
//define('WP_HOME', 'https://yourdomain.com');  // The home URL of your WordPress site (use HTTPS)
//define('WP_SITEURL', 'https://yourdomain.com'); // The URL to the WordPress core (use HTTPS)

define( 'AUTH_KEY',         'A5B+TbRpe>zVFLDiP~E@|Zw<,?@_`P<?hKFWB`{!`=Qh@EY} WR@2Jbv(foc-sy_' );
define( 'SECURE_AUTH_KEY',  'k-a6H8_8HE,Rz,,(I!@fa)&mh+stSN$rR:$=QM+ji]w!kQitNDhQoV?]qWEH3||O' );
define( 'LOGGED_IN_KEY',    'yk^JnzO9ZPxqXgvN8p@v$)cLKP J)PN.oiM9M1^.b8aH0I06OM9&sbY7I(%Gf9{w' );
define( 'NONCE_KEY',        '>`v?>VOOhRxpdmd05|HuiSOyBLJxQa2C8jgz8(Y]@$G-{mEHxp?Z2(+(9BW!A^dm' );
define( 'AUTH_SALT',        '+Hr;8N`^j#m_Di`zP^~1SpXtF`Tz-&9*R&ID*Y7nZs?2M=}w^C+: ?W-%d/e.1?A' );
define( 'SECURE_AUTH_SALT', 'wc2lVs`|`e`Xebvb?Qu7SG3A6`z)ahgx0&hsfCudKX@>nf!fdnm7v|l!K$X>q45(' );
define( 'LOGGED_IN_SALT',   'XBP9^w)&/FZQ#XhM1}@uK>1CeqMgM0g%qOeW?8^A!)pX@uWKp(`CT<1*9@&IxB;}' );
define( 'NONCE_SALT',       'V@nt:Z*UpNF[nYCACbvHEA*twsw[AAjuyu$lzZwJ*FOp8#-VhrC}>Liw6+aBdFTU' );

$table_prefix = 'wp_';

define('WP_DEBUG', true);

define('FORCE_SSL_ADMIN', true);

define('WP_DEBUG_LOG', true);
define('WP_DEBUG_DISPLAY', true);

define('WP_CONTENT_DIR', '/var/www/html/wp-content');
define('WP_CONTENT_URL', 'https://yourdomain.com/wp-content');

define('WPLANG', 'en_US');

if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}
require_once( ABSPATH . 'wp-settings.php' );

