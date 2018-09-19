<?php

class MyFontsInstaller_3285176 {

    //tell the user we got everything installed, but don't bug 'em too much
    public static function installWarning()
    {
        echo '<div id="message" class="error">';
echo '<p>You\'ve installed a MyFonts Webfonts Kit for WordPress.</p>';
echo '<p>Check out your <a href="options-general.php">settings</a> to add it to your WordPress theme!</p>';
echo '</div>';
}

//check if installation is all fine and dandy
public static function checkInstallation()
{

if (!get_option('mffonts-install-notice-3285176') ) {
add_action('admin_notices', array('MyFontsInstaller_3285176','installWarning'));
update_option('mffonts-install-notice-3285176', 'true');
}
}

public static function mffonts_loadupWebfonts()
{
$css = plugins_url() . "/MyFontsWebfontsKit/MyFontsWebfontsKit.css";
wp_enqueue_style('mf-webfonts-3285176', $css);
add_action('wp_head', array('MyFontsInstaller_3285176','mffonts_loadInline' ), 100);
}

public static function mffonts_loadInline()
{
$options['.site-title'] = get_option('mffonts-site-title-3285176', false);
$options['.site-description'] = get_option('mffonts-site-desc-3285176', false);
$options['.entry-title'] = get_option('mffonts-post-title-3285176', false);
$options['.entry-content'] = get_option('mffonts-post-body-3285176', false);
$data = "<style>";
    foreach ($options as $key => $option) {
    if ($option !== false && $option != 'none' && $option != '') {
    $data .= "$key{font-family:'$option'}";
    }
    }

    $data .= "</style>";
echo $data;
}

}