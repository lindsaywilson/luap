<?php 
	$mediumVocab = taxonomy_term_get_by_vid(2);
	$projectsVocab = taxonomy_term_get_by_vid(3);
?>
	
	<div id="disciplines">   
		<p class="filter-title">Disciplines</p>
		<ul class="reset">
			<li><a href="/portfolio" class="reset all active">All</a></li>
		</ul>
		
		<ul class="filter">
		<?php
        foreach( $mediumVocab as &$t):
			$term = taxonomy_term_load($t->tid);
			$medium = str_replace(' ','-', strtolower($term->name)); 
			$projects = array();

			$result = db_query('SELECT entity_id FROM {field_data_field_medium} n WHERE n.field_medium_tid = :tid', array(':tid' => $t->tid));
			foreach ($result as $record) {
				$nid = $record->entity_id;
				$result = db_query('SELECT field_project_tid FROM {field_data_field_project} n WHERE n.entity_id = :mid', array(':mid' => $nid));
				foreach ($result as $record) {
					$ptid = taxonomy_term_load($record->field_project_tid);
					$project = str_replace(' ','-', strtolower($ptid->name));
					if (!in_array($project, $projects)) {
						array_push($projects, $project);
					}
				}
			}
			?>
            <li><a 
            	data-projects="<?php foreach($projects as $project){ print $project.' '; }?>" 
                data-medium="<?php print $medium; ?>" 
                href="/disciplines/<?php print $medium; ?>"
                class="<?php print $medium; ?>"><?php print $term->name; ?></a></li>
		<?php endforeach; ?>
		</ul>
	</div>
    
    <div id="projects">   
		<p class="filter-title">Projects</p>
		<ul class="reset">
			<li><a href="/portfolio" class="reset all active">All</a></li>
            <li><a href="/portfolio/latest" class="latest">Latest</a></li>
		</ul>
		
		<ul class="filter">
		<?php
        foreach( $projectsVocab as &$t):
			$term = taxonomy_term_load($t->tid);
			$project = str_replace(' ','-', strtolower($term->name)); 
			$mediums = array();

			$result = db_query('SELECT entity_id FROM {field_data_field_project} n WHERE n.field_project_tid = :tid', array(':tid' => $t->tid));
			foreach ($result as $record) {
				$nid = $record->entity_id;
				$result = db_query('SELECT field_medium_tid FROM {field_data_field_medium} n WHERE n.entity_id = :mid', array(':mid' => $nid));
				foreach ($result as $record) {
					$mtid = taxonomy_term_load($record->field_medium_tid);
					$medium = str_replace(' ','-', strtolower($mtid->name));
					if (!in_array($medium, $mediums)) {
						array_push($mediums, $medium);
					}
				}
			}
			?>
			<li><a 
            	data-mediums="<?php foreach($mediums as $medium){ print $medium.' '; }?>" 
                data-project="<?php print $project; ?>" 
                href="/projects/<?php print $project; ?>"
                class="<?php print $project; ?>"><?php print $term->name; ?></a></li>
		<?php endforeach; ?>
		</ul>
	</div>