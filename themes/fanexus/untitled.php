<?php if( have_rows('team_members') ): ?>
      <?php while( have_rows('team_members') ): the_row(); 
        $image_object = get_sub_field('image');
        $image_size = 'medium';
        $image_url = $image_object['sizes'][$image_size];
    
        static $x = 1;
          echo $x;
          $x++; 
      ?>

      <div class="popup" data-popup="'popup-1">
        <div class="popup-inner">
          <h2><?php the_sub_field('name'); ?></h2>
          <img src="<?php echo $image_url; ?>"/> 
          <p class="bio"><?php the_sub_field('bio-short'); ?></p> 
          <p><?php the_sub_field('tel'); ?></p> and 
          <p><a href="mailto:<?php the_sub_field('email'); ?>"><?php the_sub_field('email'); ?></a></p>
          <a href="#" class="popup-close" data-popup-close="popup-1">x</a>

        </div>
      </div>

    <?php endwhile; ?>
  <?php endif; ?>


<div class="popup" data-popup="popup-1">
  <div class="popup-inner">
    <h2>About Eric Warlick</h2>
    <p><img src="http://l3z.3c6.myftpupload.com/wp-content/uploads/2017/05/new1f.png"/> Eric Warlick brings 23 years’ experience in RIA and custody/clearing sales to his new role as president of FA Nexus. In recent years, he served as managing partner and co-founder of an RIA platform services provider, with $2.3 billion in assets, and principal and co-founder of Martin Capital Partners, a $140 million RIA. He previously served as a vice president of TD Ameritrade, Fidelity Investments and Schwab Institutional. He earned a bachelor’s degree from the University of Oregon. Eric can be reached at 503.360.2943 and <a href="mailto:ewarlick@fa-nexus.com">ewarlick@FA-Nexus.com</a></p>
    <!--<p><a href="#" data-popup-close="popup-1">Close</a></p>-->
    <a href="#" class="popup-close" data-popup-close="popup-1">x</a>
  </div>
</div>