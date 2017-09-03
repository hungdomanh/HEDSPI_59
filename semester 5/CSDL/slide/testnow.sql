--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- Name: NhaCC; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA "NhaCC";


ALTER SCHEMA "NhaCC" OWNER TO postgres;

--
-- Name: store; Type: SCHEMA; Schema: -; Owner: postgres
--

CREATE SCHEMA store;


ALTER SCHEMA store OWNER TO postgres;

--
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = "NhaCC", pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: Cungcap; Type: TABLE; Schema: NhaCC; Owner: postgres; Tablespace: 
--

CREATE TABLE "Cungcap" (
    "MSNCC" integer NOT NULL,
    "MSMH" integer NOT NULL,
    "Giatien" integer
);


ALTER TABLE "Cungcap" OWNER TO postgres;

--
-- Name: Mathang; Type: TABLE; Schema: NhaCC; Owner: postgres; Tablespace: 
--

CREATE TABLE "Mathang" (
    "MSMH" integer NOT NULL,
    "TenMH" character varying(30),
    "Mausac" character varying(10)
);


ALTER TABLE "Mathang" OWNER TO postgres;

--
-- Name: NCC; Type: TABLE; Schema: NhaCC; Owner: postgres; Tablespace: 
--

CREATE TABLE "NCC" (
    "MSNCC" integer NOT NULL,
    "TenNCC" character varying(30),
    "DiaChi" character varying(100)
);


ALTER TABLE "NCC" OWNER TO postgres;

SET search_path = public, pg_catalog;

--
-- Name: orders; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE orders (
    orderid integer NOT NULL,
    customerid integer NOT NULL
);


ALTER TABLE orders OWNER TO postgres;

--
-- Name: orders_orderid_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE orders_orderid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE orders_orderid_seq OWNER TO postgres;

--
-- Name: orders_orderid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE orders_orderid_seq OWNED BY orders.orderid;


--
-- Name: sujects; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE sujects (
    sid character(5) NOT NULL,
    sname character varying(20),
    scredits integer,
    sid_required character(5)
);


ALTER TABLE sujects OWNER TO postgres;

--
-- Name: users; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE users (
    userid integer NOT NULL
);


ALTER TABLE users OWNER TO postgres;

--
-- Name: users_userid_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE users_userid_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE users_userid_seq OWNER TO postgres;

--
-- Name: users_userid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE users_userid_seq OWNED BY users.userid;


SET search_path = store, pg_catalog;

--
-- Name: Customer; Type: TABLE; Schema: store; Owner: postgres; Tablespace: 
--

CREATE TABLE "Customer" (
    "CustomerID" character(6) NOT NULL,
    "LastName" character varying(20),
    "FirstName" character varying(10),
    "Address" character varying(50),
    "City" character varying(20),
    "State" character(2),
    "Zip" character(5),
    "Phone" character varying(15)
);


ALTER TABLE "Customer" OWNER TO postgres;

--
-- Name: Order; Type: TABLE; Schema: store; Owner: postgres; Tablespace: 
--

CREATE TABLE "Order" (
    "ProductID" character(6) NOT NULL,
    "OrderID" character(6) NOT NULL,
    "CustomerID" character(6) NOT NULL,
    "PurchaseDate" date,
    "Quantity" integer,
    "TotalCost" money
);


ALTER TABLE "Order" OWNER TO postgres;

--
-- Name: Product; Type: TABLE; Schema: store; Owner: postgres; Tablespace: 
--

CREATE TABLE "Product" (
    "ProductID" character(6) NOT NULL,
    "ProductName" character varying(40),
    "Model" character varying(10),
    "Manufacturer" character varying(40),
    "UnitPrice" money,
    "Inventory" integer
);


ALTER TABLE "Product" OWNER TO postgres;

SET search_path = public, pg_catalog;

--
-- Name: orderid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY orders ALTER COLUMN orderid SET DEFAULT nextval('orders_orderid_seq'::regclass);


--
-- Name: userid; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY users ALTER COLUMN userid SET DEFAULT nextval('users_userid_seq'::regclass);


SET search_path = "NhaCC", pg_catalog;

--
-- Data for Name: Cungcap; Type: TABLE DATA; Schema: NhaCC; Owner: postgres
--

COPY "Cungcap" ("MSNCC", "MSMH", "Giatien") FROM stdin;
1	1	150
1	2	250
1	3	350
1	4	50
2	1	50
2	2	450
2	3	250
2	4	150
\.


--
-- Data for Name: Mathang; Type: TABLE DATA; Schema: NhaCC; Owner: postgres
--

COPY "Mathang" ("MSMH", "TenMH", "Mausac") FROM stdin;
1	Mat hang 1	do
2	Mat hang 2	xanh
3	Mat hang 3	xanh
4	Mat hang 4	do
\.


--
-- Data for Name: NCC; Type: TABLE DATA; Schema: NhaCC; Owner: postgres
--

COPY "NCC" ("MSNCC", "TenNCC", "DiaChi") FROM stdin;
1	Cong ty A	Dia chi A
2	Cong ty B	Dia chi B
3	Cong ty C	Dia chi C
\.


SET search_path = public, pg_catalog;

--
-- Data for Name: orders; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY orders (orderid, customerid) FROM stdin;
\.


--
-- Name: orders_orderid_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('orders_orderid_seq', 1, false);


--
-- Data for Name: sujects; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY sujects (sid, sname, scredits, sid_required) FROM stdin;
IT010	Tr¡ tu? nhƒn t?o	3	IT005
IT005	Cau truc DL va GT	2	IT001
IT001	Tin hoc dai cuong	2	\N
IT006	CSDL	3	IT001
\.


--
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY users (userid) FROM stdin;
\.


--
-- Name: users_userid_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('users_userid_seq', 1, false);


SET search_path = store, pg_catalog;

--
-- Data for Name: Customer; Type: TABLE DATA; Schema: store; Owner: postgres
--

COPY "Customer" ("CustomerID", "LastName", "FirstName", "Address", "City", "State", "Zip", "Phone") FROM stdin;
BLU003	AAAA	Katie	342 Pine	Hammond	IN	46200	555-9242
BLU001	Blum	Jessica	229 State	Whiting	IN	46300	555-0921
BLU005	Bbbbbbbb	Rich	123 Main St.	Chicago	IL	60633	555-1234
WIL001	Williams	Frank	456 Oak St.	Hammond	IN	46102	\N
\.


--
-- Data for Name: Order; Type: TABLE DATA; Schema: store; Owner: postgres
--

COPY "Order" ("ProductID", "OrderID", "CustomerID", "PurchaseDate", "Quantity", "TotalCost") FROM stdin;
LAP001	ODR001	BLU001	2012-08-21	1	$1.30
LAP002	ODR002	BLU003	2012-02-03	2	$2.00
LAP001	ORD003	WIL001	2012-06-06	1	$1.30
\.


--
-- Data for Name: Product; Type: TABLE DATA; Schema: store; Owner: postgres
--

COPY "Product" ("ProductID", "ProductName", "Model", "Manufacturer", "UnitPrice", "Inventory") FROM stdin;
LAP001	Vaio CR31Z	CR	Sony Vaio	$1.30	5
LAP002	HP AZE	HP	\N	$1.00	18
LAP003	HP 34	HP	HP	$1,000.00	200
\.


SET search_path = "NhaCC", pg_catalog;

--
-- Name: pk-Cungcap; Type: CONSTRAINT; Schema: NhaCC; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "Cungcap"
    ADD CONSTRAINT "pk-Cungcap" PRIMARY KEY ("MSNCC", "MSMH");


--
-- Name: pk-Mathang; Type: CONSTRAINT; Schema: NhaCC; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "Mathang"
    ADD CONSTRAINT "pk-Mathang" PRIMARY KEY ("MSMH");


--
-- Name: pri-key-NCC; Type: CONSTRAINT; Schema: NhaCC; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "NCC"
    ADD CONSTRAINT "pri-key-NCC" PRIMARY KEY ("MSNCC");


SET search_path = public, pg_catalog;

--
-- Name: pk; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY users
    ADD CONSTRAINT pk PRIMARY KEY (userid);


--
-- Name: pk_order; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY orders
    ADD CONSTRAINT pk_order PRIMARY KEY (orderid);


--
-- Name: sujects_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY sujects
    ADD CONSTRAINT sujects_pkey PRIMARY KEY (sid);


SET search_path = store, pg_catalog;

--
-- Name: pk_Customer; Type: CONSTRAINT; Schema: store; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "Customer"
    ADD CONSTRAINT "pk_Customer" PRIMARY KEY ("CustomerID");


--
-- Name: pk_Product; Type: CONSTRAINT; Schema: store; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "Product"
    ADD CONSTRAINT "pk_Product" PRIMARY KEY ("ProductID");


--
-- Name: pk_order; Type: CONSTRAINT; Schema: store; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY "Order"
    ADD CONSTRAINT pk_order PRIMARY KEY ("OrderID");


SET search_path = "NhaCC", pg_catalog;

--
-- Name: fk-Cungcap-Mathang; Type: FK CONSTRAINT; Schema: NhaCC; Owner: postgres
--

ALTER TABLE ONLY "Cungcap"
    ADD CONSTRAINT "fk-Cungcap-Mathang" FOREIGN KEY ("MSMH") REFERENCES "Mathang"("MSMH") ON DELETE CASCADE;


--
-- Name: pk-Cungcap-NCC; Type: FK CONSTRAINT; Schema: NhaCC; Owner: postgres
--

ALTER TABLE ONLY "Cungcap"
    ADD CONSTRAINT "pk-Cungcap-NCC" FOREIGN KEY ("MSNCC") REFERENCES "NCC"("MSNCC");


SET search_path = public, pg_catalog;

--
-- Name: fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY orders
    ADD CONSTRAINT fk FOREIGN KEY (customerid) REFERENCES users(userid);


SET search_path = store, pg_catalog;

--
-- Name: fk_order_customer; Type: FK CONSTRAINT; Schema: store; Owner: postgres
--

ALTER TABLE ONLY "Order"
    ADD CONSTRAINT fk_order_customer FOREIGN KEY ("CustomerID") REFERENCES "Customer"("CustomerID");


--
-- Name: fk_order_product; Type: FK CONSTRAINT; Schema: store; Owner: postgres
--

ALTER TABLE ONLY "Order"
    ADD CONSTRAINT fk_order_product FOREIGN KEY ("ProductID") REFERENCES "Product"("ProductID");


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- Name: store; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA store FROM PUBLIC;
REVOKE ALL ON SCHEMA store FROM postgres;
GRANT USAGE ON SCHEMA store TO salesman;


--
-- Name: Customer; Type: ACL; Schema: store; Owner: postgres
--

REVOKE ALL ON TABLE "Customer" FROM PUBLIC;
REVOKE ALL ON TABLE "Customer" FROM postgres;
GRANT ALL ON TABLE "Customer" TO postgres;
GRANT INSERT,DELETE,UPDATE ON TABLE "Customer" TO salesman;
GRANT SELECT ON TABLE "Customer" TO salesman WITH GRANT OPTION;
GRANT SELECT ON TABLE "Customer" TO PUBLIC;


--
-- Name: Order; Type: ACL; Schema: store; Owner: postgres
--

REVOKE ALL ON TABLE "Order" FROM PUBLIC;
REVOKE ALL ON TABLE "Order" FROM postgres;
GRANT ALL ON TABLE "Order" TO postgres;
GRANT SELECT,INSERT,DELETE,UPDATE ON TABLE "Order" TO salesman;


--
-- Name: Product; Type: ACL; Schema: store; Owner: postgres
--

REVOKE ALL ON TABLE "Product" FROM PUBLIC;
REVOKE ALL ON TABLE "Product" FROM postgres;
GRANT ALL ON TABLE "Product" TO postgres;
GRANT SELECT ON TABLE "Product" TO salesman;


--
-- PostgreSQL database dump complete
--

