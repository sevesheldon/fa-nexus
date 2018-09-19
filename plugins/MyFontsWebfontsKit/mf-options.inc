<?php
// create custom plugin settings menu
add_action('admin_menu', array('MyFontsSettings_3285176','mf_create_menu'));

class MyFontsSettings_3285176
{

	public static function mf_create_menu()
	{
		//create new top-level menu
		add_options_page('MyFonts Webfont Kit Settings', 'MyFonts (3285176)', 'manage_options', 'mf_settings_page_3285176', array('MyFontsSettings_3285176','mf_settings_page'), 'dashicons-editor-spellcheck');
		//call register settings function
		add_action('admin_init',array('MyFontsSettings_3285176','register_mf_settings'));
	}

	public static function register_mf_settings()
	{
		//register our settings
		register_setting('mf-settings-group-3285176', 'mffonts-site-title-3285176');
		register_setting('mf-settings-group-3285176', 'mffonts-site-desc-3285176');
		register_setting('mf-settings-group-3285176', 'mffonts-post-title-3285176');
		register_setting('mf-settings-group-3285176', 'mffonts-post-body-3285176');
	}

	public static function createFSSelect($fonts, $setting)
	{
		//create webfont selection
		$none = true;
		$s = esc_attr(get_option($setting));
		echo "<select name='$setting'>";
foreach ($fonts as $font) {
if ($s === $font) {
echo "<option value='$font' selected>$font</option>";
$none = false;
continue;
}
echo "<option value='$font'>$font</option>";
}
if ($none || $s === "none") {
echo "<option value='none' selected>None</option>";
}
if (!$none && $s !== "none") {
echo "<option value='none'>None</option>";
}
echo "</select>";
}

public static function mf_settings_page()
{

$css = plugins_url() . "/MyFontsWebfontsKit/mf_options.css";
wp_enqueue_style('mf-webfonts-3180405-settings', $css);

$fonts = array('CoreSansDS15Thin', 'CoreSansDS25Light', 'CoreSansDS25LightItalic', 'CoreSansDS35Regular', 'CoreSansDS55Bold');

?>
<div class="wrap">
    <div class="elementWrapper">
        <div class="header">&nbsp;</div>
        <h1 class="subTitle">Webfont Settings</h1>
        <h3 class="description">Here you can add your webfonts kit to specific WordPress elements</h3>
        <form method="post" action="options.php">

            <?php settings_fields('mf-settings-group-3285176'); ?>
            <?php do_settings_sections('mf-settings-group-3285176'); ?>
            <div class="elementTable">
                <div class="elementRow">
                    <label for="mffonts-site-title-3285176">Site Title</label>
                    <?php self::createFSSelect($fonts, 'mffonts-site-title-3285176') ?>
                </div>

                <div class="elementRow">
                    <label for="mffonts-site-desc-3285176">Site Description</label>
                    <?php self::createFSSelect($fonts, 'mffonts-site-desc-3285176') ?>
                </div>

                <div class="elementRow">
                    <label for="mffonts-post-title-3285176">Post Title</label>
                    <?php self::createFSSelect($fonts, 'mffonts-post-title-3285176') ?>
                </div>

                <div class="elementRow">
                    <label for="mffonts-post-body-3285176">Post Body</label>
                    <?php self::createFSSelect($fonts, 'mffonts-post-body-3285176') ?>
                </div>
            </div>

            <?php submit_button(); ?>
        </form></div>
</div>
<?php
	}
}