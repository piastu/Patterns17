<?php

echo 'Document root: '.$_SERVER['DOCUMENT_ROOT'].'<br>';
echo 'Current directory: '.__DIR__.'<br>';
echo realpath($_SERVER['DOCUMENT_ROOT']);