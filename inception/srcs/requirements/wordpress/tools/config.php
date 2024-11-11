<?php
/**
 * The base configuration for WordPress
 *
 * This file contains the following configurations:
 *   - MySQL settings
 *   - WordPress database table prefix
 *   - Authentication unique keys and salts
 *   - WordPress language
 *   - For advanced options, see the Codex.
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - These are the database settings you should configure ** //
define('DB_NAME', 'mariadb_db'); // The name of the database for WordPress
define('DB_USER', 'pclaus');      // Your database username
define('DB_PASSWORD', 'pclaus');  // Your database password
define('DB_HOST', 'mariadb');     // The hostname of your MariaDB container (service name from Docker Compose)
define('DB_CHARSET', 'utf8mb4');  // Database charset
define('DB_COLLATE', '');         // Database collation (empty is default)

// ** WordPress site and home URL (Important for Nginx and SSL)** //
define('WP_HOME', 'https://yourdomain.com');  // The home URL of your WordPress site (use HTTPS)
define('WP_SITEURL', 'https://yourdomain.com'); // The URL to the WordPress core (use HTTPS)

// ** Authentication unique keys and salts ** //
// You can generate these at: https://api.wordpress.org/secret-key/1.1/salt/
define('AUTH_KEY',         'your-random-key-here');
define('SECURE_AUTH_KEY',  'your-random-key-here');
define('LOGGED_IN_KEY',    'your-random-key-here');
define('NONCE_KEY',        'your-random-key-here');
define('AUTH_SALT',        'your-random-key-here');
define('SECURE_AUTH_SALT', 'your-random-key-here');
define('LOGGED_IN_SALT',   'your-random-key-here');
define('NONCE_SALT',       'your-random-key-here');

// ** Database Table prefix ** //
// You can have multiple WordPress installations in one database if you give each a unique prefix
$table_prefix = 'wp_';

// ** Debugging mode ** //
// Set this to true for debugging during development
define('WP_DEBUG', false);

// ** WordPress Content Directory (if you want to store content outside the web root) ** //
// Uncomment the following lines to change the location of WordPress content
// define('WP_CONTENT_DIR', '/path/to/your/content');
// define('WP_CONTENT_URL', 'https://yourdomain.com/wp-content');

// ** SSL settings (force SSL in admin and login) ** //
define('FORCE_SSL_ADMIN', true);

// ** Cache Settings (optional but recommended)** //
// You can enable caching to improve performance, depending on your setup
// define('WP_CACHE', true);

// ** Multisite settings (if you're using WordPress Multisite)** //
// Uncomment to enable multisite (only if you need this functionality)
// define('WP_ALLOW_MULTISITE', true);

// ** Custom file paths ** //
define('WP_DEBUG_LOG', true);
define('WP_DEBUG_DISPLAY', false);

// ** Set custom content directory (optional) ** //
define('WP_CONTENT_DIR', '/var/www/html/wp-content');
define('WP_CONTENT_URL', 'https://yourdomain.com/wp-content');

// ** Set upload directory (optional) ** //
// define('UPLOADS', 'wp-content/uploads');

// ** Set custom language (optional)** //
// Uncomment and change the value to set a different language for WordPress
// define('WPLANG', 'en_US');

// ** Absolute path to the WordPress directory ** //
if ( ! defined( 'ABSPATH' ) ) {
    define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}
require_once( ABSPATH . 'wp-settings.php' );

