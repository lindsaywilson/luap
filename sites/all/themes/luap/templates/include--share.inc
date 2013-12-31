
<?php

global $base_url;
$url = $base_url.urlencode($node_url);

$media = file_create_url($node->field_image['und'][0]['uri']);

?>

	<span class="title">Share</span>
	
    <a onclick='window.open("http://www.pinterest.com/pin/create/button/?url=<?php print $url; ?>&media=<?php print $media; ?>&description=<?php $title ?>", "", "height=300, width=730");' class="pinterest">Pinterest</a>
		
    <a onclick='window.open("https://twitter.com/share?url=<?php print $url; ?>&via=luap_nosnibor&text=<?php print urlencode($title) ?>", "", "height=236, width=516");'  class="twitter">Twitter</a>
	
    <a onclick='window.open("https://plus.google.com/share?url=<?php print $url; ?>", "", "height=480, width=500");' class="google">Google+</a>
	
    <a onclick='window.open("https://www.facebook.com/dialog/feed?app_id=511652485599977&display=popup&link=<?php echo $url;?>&name=<?php $title ?>&redirect_uri=<?php echo $base_url.'/close.html';?>", "", "height=236, width=516");' class="facebook">Facebook</a>