-- MySQL dump 10.13  Distrib 5.7.20, for Linux (x86_64)
--
-- Host: localhost    Database: trainning_mysql
-- ------------------------------------------------------
-- Server version	5.7.20-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `sinhvien`
--

DROP TABLE IF EXISTS `sinhvien`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `sinhvien` (
  `id` int(6) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `birth` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `mssv` int(10) DEFAULT NULL,
  `phone` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  `class` varchar(255) CHARACTER SET utf8 DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=58 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `sinhvien`
--

LOCK TABLES `sinhvien` WRITE;
/*!40000 ALTER TABLE `sinhvien` DISABLE KEYS */;
INSERT INTO `sinhvien` VALUES (4,'Hùng Do','16/08/1996',20142023,'012343535','hedspi-C1'),(5,'Tuan111','20.11.1996',20140043,'123456789','Hedspi C K59'),(7,'Đặng Quốc Việt','17.07.1996',20140106,'123456789','Hedspi C K59'),(8,'Tuan111','20.11.1996',20140043,'123456789','Hedspi C K59'),(9,'Hoàng Văn Bảo','02.11.1996',20140334,'123456789','Hedspi C K59'),(10,'Lưu Trang Anh','01.03.1996',20140449,'123456789','Hedspi C K59'),(11,'Lưu Thanh Tuấn','30.06.1996',20140464,'123456789','Hedspi C K59'),(12,'Phạm Hoàng Anh','11.01.1996',20140686,'123456789','Hedspi C K59'),(13,'Phạm Thị Hiền Anh','11.06.1996',20140711,'123456789','Hedspi C K59'),(14,'Phạm Khắc Việt Anh','28.10.1996',20140919,'123456789','Hedspi C K59'),(15,'Đỗ Hoàng Gia Bảo','12.05.1996',20140921,'123456789','Hedspi C K59'),(16,'Trần Thị Minh Châu','16.08.1996',20140934,'123456789','Hedspi C K59'),(17,' Tăng Phương Chi','31.12.1996',20140951,'123456789','Hedspi C K59'),(18,'Gan Feng Du','24.04.1996',20141120,'123456789','Hedspi C K59'),(19,'Phạm Tiến Dũng','19.02.1996',20141143,'123456789','Hedspi C K59'),(26,'sadasdasdfsdfs','',0,'',''),(30,'a17','',NULL,'',''),(52,'asddddd','',0,'',''),(53,'asdddddaaa','',0,'',''),(55,'aaa','',0,'',''),(56,'Tuan111','20.11.1996',20140043,'123456789','Hedspi C K59'),(57,'aaaaaaaaaaaa','14.02.1999',1236455,'23476343','HEDSPI');
/*!40000 ALTER TABLE `sinhvien` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2017-11-02 15:26:57
