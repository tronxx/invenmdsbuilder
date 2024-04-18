object Form_consuinv: TForm_consuinv
  Left = 102
  Top = 117
  Width = 1109
  Height = 595
  BorderWidth = 1
  Caption = 'Consulta de Artículos en Inventario'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefaultPosOnly
  Scaled = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 353
    Width = 1091
    Height = 3
    Cursor = crVSplit
    Align = alTop
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 53
    Width = 1091
    Height = 180
    Align = alTop
    Caption = 'Tarjeta del Artículo : '
    TabOrder = 0
    object etiqcodigo: TLabel
      Left = 16
      Top = 19
      Width = 33
      Height = 13
      Caption = '&Codigo'
      FocusControl = edt_codigo
    end
    object etiqdesc: TLabel
      Left = 168
      Top = 16
      Width = 56
      Height = 13
      Caption = 'Descripción'
    end
    object etiqtipo: TLabel
      Left = 448
      Top = 62
      Width = 21
      Height = 13
      Caption = 'Tipo'
    end
    object etiqcodaux: TLabel
      Left = 20
      Top = 39
      Width = 29
      Height = 13
      Caption = 'Grupo'
    end
    object etiqprove: TLabel
      Left = 197
      Top = 38
      Width = 28
      Height = 13
      Caption = 'Prove'
    end
    object Label1: TLabel
      Left = 441
      Top = 38
      Width = 28
      Height = 13
      Caption = 'Línea'
    end
    object Label2: TLabel
      Left = 454
      Top = 86
      Width = 15
      Height = 13
      Caption = 'Iva'
    end
    object Label3: TLabel
      Left = 278
      Top = 38
      Width = 24
      Height = 13
      Caption = 'Diary'
    end
    object lbl_costos: TLabel
      Left = 12
      Top = 63
      Width = 37
      Height = 13
      Caption = 'Costo S'
    end
    object lbl_coston: TLabel
      Left = 11
      Top = 86
      Width = 38
      Height = 13
      Caption = 'Costo N'
    end
    object lbl_preciomds: TLabel
      Left = 131
      Top = 63
      Width = 64
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Precio MDS'
    end
    object lbl_preciofide: TLabel
      Left = 128
      Top = 86
      Width = 67
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Precio SUBS'
    end
    object Label8: TLabel
      Left = 262
      Top = 63
      Width = 24
      Height = 13
      Caption = 'MUB'
    end
    object Label9: TLabel
      Left = 262
      Top = 86
      Width = 24
      Height = 13
      Caption = 'MUB'
    end
    object Label12: TLabel
      Left = 525
      Top = 85
      Width = 30
      Height = 13
      Caption = 'Situac'
    end
    object Label13: TLabel
      Left = 499
      Top = 16
      Width = 56
      Height = 13
      Caption = 'Ult.Cam.Pre'
    end
    object Label14: TLabel
      Left = 516
      Top = 38
      Width = 41
      Height = 13
      Caption = 'Vigencia'
    end
    object Label15: TLabel
      Left = 536
      Top = 61
      Width = 18
      Height = 13
      Caption = 'Alta'
    end
    object Label16: TLabel
      Left = 525
      Top = 108
      Width = 30
      Height = 13
      Caption = 'Marca'
    end
    object Label22: TLabel
      Left = 9
      Top = 131
      Width = 36
      Height = 13
      Caption = 'Descri2'
    end
    object lbl_prmay: TLabel
      Left = 798
      Top = 15
      Width = 55
      Height = 12
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Mayoreo'
    end
    object lbl_prmayneto: TLabel
      Left = 786
      Top = 39
      Width = 68
      Height = 12
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Mayoreo Neto'
    end
    object Label4: TLabel
      Left = 786
      Top = 62
      Width = 68
      Height = 12
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'MUB. Costo'
    end
    object Label5: TLabel
      Left = 157
      Top = 108
      Width = 36
      Height = 13
      Caption = 'C.Repo'
    end
    object Label7: TLabel
      Left = 262
      Top = 109
      Width = 24
      Height = 13
      Caption = 'MUB'
    end
    object lbl_prxtensa: TLabel
      Left = 948
      Top = 15
      Width = 55
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Pr.Extensa'
    end
    object lbl_cosxtensa: TLabel
      Left = 936
      Top = 39
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Costo Repo'
    end
    object Label25: TLabel
      Left = 514
      Top = 133
      Width = 40
      Height = 13
      Caption = 'Garantia'
    end
    object Label26: TLabel
      Left = 442
      Top = 109
      Width = 26
      Height = 13
      Caption = 'Plazo'
    end
    object Label27: TLabel
      Left = 647
      Top = 15
      Width = 55
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Filial'
    end
    object Label28: TLabel
      Left = 635
      Top = 39
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Filial Neto'
    end
    object lbl_maximo: TLabel
      Left = 565
      Top = 156
      Width = 51
      Height = 13
      Caption = 'lbl_maximo'
    end
    object Label6: TLabel
      Left = 360
      Top = 63
      Width = 35
      Height = 13
      Caption = 'Mínimo'
    end
    object Label10: TLabel
      Left = 333
      Top = 86
      Width = 62
      Height = 13
      Caption = 'Max.Mnudeo'
    end
    object Label11: TLabel
      Left = 337
      Top = 109
      Width = 58
      Height = 13
      Caption = 'Max.Myoreo'
    end
    object Label23: TLabel
      Left = 9
      Top = 154
      Width = 35
      Height = 13
      Caption = 'Cat.Sat'
    end
    object lbl_oferta: TLabel
      Left = 636
      Top = 88
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Oferta'
    end
    object lbl_inivig: TLabel
      Left = 636
      Top = 110
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Inicia'
    end
    object lbl_finvig: TLabel
      Left = 636
      Top = 133
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Termina'
    end
    object lbl_mubofer: TLabel
      Left = 636
      Top = 157
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'M.U.B '
    end
    object Label24: TLabel
      Left = 636
      Top = 62
      Width = 68
      Height = 12
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'MUB. Costo'
    end
    object lbl_outlet: TLabel
      Left = 786
      Top = 88
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Outlet'
    end
    object lbl_inioutlet: TLabel
      Left = 786
      Top = 110
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Inicia'
    end
    object lbl_finoutlet: TLabel
      Left = 786
      Top = 133
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Termina'
    end
    object lbl_muboutlet: TLabel
      Left = 786
      Top = 157
      Width = 68
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'M.U.B '
    end
    object Label29: TLabel
      Left = 948
      Top = 61
      Width = 55
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Servicio'
    end
    object edt_codigo: TEdit
      Left = 51
      Top = 13
      Width = 113
      Height = 21
      CharCase = ecUpperCase
      TabOrder = 0
      OnKeyDown = edt_codigoKeyDown
    end
    object DBEdit1: TDBEdit
      Left = 231
      Top = 13
      Width = 234
      Height = 21
      DataField = 'DESCRI'
      DataSource = dts_inven
      TabOrder = 1
    end
    object DBEdit2: TDBEdit
      Left = 472
      Top = 59
      Width = 40
      Height = 21
      DataField = 'TIPO'
      DataSource = dts_inven
      TabOrder = 2
    end
    object DBEdit3: TDBEdit
      Left = 51
      Top = 36
      Width = 113
      Height = 21
      DataField = 'COD2'
      DataSource = dts_inven
      TabOrder = 3
    end
    object DBEdit4: TDBEdit
      Left = 231
      Top = 36
      Width = 42
      Height = 21
      DataField = 'PROVE'
      DataSource = dts_inven
      TabOrder = 4
    end
    object dbedt_linea: TDBEdit
      Left = 472
      Top = 36
      Width = 41
      Height = 21
      DataField = 'LINEA'
      DataSource = dts_inven
      TabOrder = 5
      OnDblClick = dbedt_lineaDblClick
    end
    object dxDBCurrencyEdit1: TdxDBCurrencyEdit
      Left = 472
      Top = 82
      Width = 40
      TabOrder = 6
      Alignment = taRightJustify
      DataField = 'PIVA'
      DataSource = dts_inven
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object DBEdit6: TDBEdit
      Left = 307
      Top = 36
      Width = 131
      Height = 21
      DataField = 'GRUPO'
      DataSource = dts_diary
      TabOrder = 7
    end
    object dbedt_costos: TdxDBCurrencyEdit
      Left = 51
      Top = 59
      Width = 75
      TabOrder = 8
      Alignment = taRightJustify
      DataField = 'COSTOS'
      DataSource = dts_inven
      DisplayFormat = '$,0.00;-$,0.00'
      StoredValues = 1
    end
    object dbedt_coston: TdxDBCurrencyEdit
      Left = 51
      Top = 82
      Width = 75
      TabOrder = 9
      Alignment = taRightJustify
      DataField = 'COSTON'
      DataSource = dts_inven
      DisplayFormat = '$,0.00;-$,0.00'
      StoredValues = 1
    end
    object dbedt_preciomds: TdxDBCurrencyEdit
      Left = 198
      Top = 59
      Width = 60
      TabOrder = 10
      Alignment = taRightJustify
      DataField = 'PRECIO'
      DataSource = dts_inven
      DisplayFormat = '$,0.00;-$,0.00'
      StoredValues = 1
    end
    object dbedt_preciofide: TdxDBCurrencyEdit
      Left = 198
      Top = 82
      Width = 60
      TabOrder = 11
      Alignment = taRightJustify
      DataField = 'PRECELEC'
      DataSource = dts_inven
      DisplayFormat = '$,0.00;-$,0.00'
      StoredValues = 1
    end
    object dxDBCurrencyEdit7: TdxDBCurrencyEdit
      Left = 288
      Top = 59
      Width = 40
      TabOrder = 12
      Alignment = taRightJustify
      DataField = 'mubmds'
      DataSource = dts_inven
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object dxDBCurrencyEdit8: TdxDBCurrencyEdit
      Left = 288
      Top = 82
      Width = 40
      TabOrder = 13
      Alignment = taRightJustify
      DataField = 'mubelec'
      DataSource = dts_inven
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object DBEdit7: TDBEdit
      Left = 558
      Top = 82
      Width = 70
      Height = 21
      DataField = 'EMPAQE'
      DataSource = dts_inven
      TabOrder = 14
    end
    object DBEdit8: TDBEdit
      Left = 559
      Top = 13
      Width = 70
      Height = 21
      DataField = 'FECHA'
      DataSource = dts_invulpre
      TabOrder = 15
    end
    object DBEdit9: TDBEdit
      Left = 559
      Top = 36
      Width = 70
      Height = 21
      DataField = 'FECINIVIG'
      DataSource = dts_invulpre
      TabOrder = 16
    end
    object DBEdit10: TDBEdit
      Left = 558
      Top = 59
      Width = 70
      Height = 21
      DataField = 'FECALTA'
      DataSource = dts_inven
      TabOrder = 17
    end
    object lkcmb_codigos: TDBLookupComboBox
      Left = 296
      Top = 13
      Width = 145
      Height = 21
      DropDownWidth = 300
      KeyField = 'CODIGO'
      ListField = 'CODIGO;DESCRI'
      ListSource = dts_buscod
      TabOrder = 18
      Visible = False
      OnExit = lkcmb_codigosExit
      OnKeyDown = lkcmb_codigosKeyDown
    end
    object DBEdit11: TDBEdit
      Left = 558
      Top = 105
      Width = 70
      Height = 21
      DataField = 'CODIGO'
      DataSource = dts_marca
      TabOrder = 19
    end
    object DBEdit5: TDBEdit
      Left = 51
      Top = 129
      Width = 461
      Height = 21
      DataField = 'DESCRI'
      DataSource = dts_descri2
      TabOrder = 20
    end
    object edt_preciomay: TdxCurrencyEdit
      Left = 856
      Top = 13
      Width = 75
      TabOrder = 21
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_mayneto: TdxCurrencyEdit
      Left = 856
      Top = 36
      Width = 75
      TabOrder = 22
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_mubmay: TdxCurrencyEdit
      Left = 856
      Top = 59
      Width = 75
      Style.ButtonStyle = btsDefault
      Style.Edges = [edgLeft, edgTop, edgRight, edgBottom]
      TabOrder = 23
      Alignment = taRightJustify
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object edt_mubcext: TdxCurrencyEdit
      Left = 288
      Top = 105
      Width = 40
      Style.ButtonStyle = btsDefault
      Style.Edges = [edgLeft, edgTop, edgRight, edgBottom]
      TabOrder = 24
      Alignment = taRightJustify
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object edt_costocext: TdxCurrencyEdit
      Left = 198
      Top = 105
      Width = 60
      TabOrder = 25
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_garantia: TEdit
      Left = 558
      Top = 129
      Width = 70
      Height = 21
      TabOrder = 26
    end
    object edt_plazo: TEdit
      Left = 472
      Top = 105
      Width = 40
      Height = 21
      TabOrder = 27
    end
    object edt_prfilial: TdxCurrencyEdit
      Left = 706
      Top = 13
      Width = 75
      TabOrder = 28
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_prfilialneto: TdxCurrencyEdit
      Left = 706
      Top = 36
      Width = 75
      TabOrder = 29
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_precioext: TdxCurrencyEdit
      Left = 1009
      Top = 13
      Width = 75
      TabOrder = 30
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_costoext: TdxCurrencyEdit
      Left = 1009
      Top = 36
      Width = 75
      TabOrder = 31
      Alignment = taRightJustify
      StoredValues = 1
    end
    object btn_vercambiosprecio: TBitBtn
      Left = 947
      Top = 111
      Width = 137
      Height = 25
      Action = despliega_cambios_precio
      Caption = 'Cambios de Precio'
      TabOrder = 32
      Visible = False
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000FFFF000000000000FF00FF00FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF00FF000000FF000000FFFFFF00FF000000FF000000FF00FF000000
        0000FFFF0000FFFF0000FFFF000000000000FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF00FF000000FF000000FFFFFF00FF000000FF00000000000000FFFF
        0000FFFF0000FFFF000000000000000000000000000000000000FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FF000000FF000000FFFFFF00FFFF0000FFFF
        0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FF000000FF000000FFFFFF0000000000FFFF
        00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF00FFFFFF00FF000000FF000000FFFFFF00FFFFFF00FF00FF000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000000000FFFFFF00FF000000FF000000FFFFFF00FFFFFF00FF00FF000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000000000FF
        FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00FF000000
        000000FFFF000000000000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
        0000000000000000000000000000000000000000000000000000FF00FF000000
        0000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFFFF0000FF
        FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00FF00FF00
        FF000000000000000000FF00FF000000000000FFFF00FFFFFF0000000000FFFF
        FF0000000000FFFFFF00FFFFFF00FFFFFF000000FF000000FF00FF000000FF00
        0000FF00FF00FF00FF00FF00FF00FF00FF000000000000FFFF00FFFFFF000000
        000000000000FFFFFF00FFFFFF00FFFFFF000000FF000000FF00FF000000FF00
        00000000FF000000FF00FF00FF00FF00FF00FF00FF0000000000000000000000
        00000000FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF00FF00FF00FF00
        FF000000FF000000FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF000000
        FF000000FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF000000FF000000
        FF00FF00FF00FF000000FF000000FF00FF00FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF000000FF000000FF00FFFFFF000000FF000000FF000000FF000000
        FF00FF00FF00FF000000FF000000FF00FF00FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF000000FF000000FF00FFFFFF000000FF000000FF00}
    end
    object edt_minimo: TdxCurrencyEdit
      Left = 397
      Top = 59
      Width = 40
      TabOrder = 33
      Alignment = taRightJustify
      DecimalPlaces = 0
      DisplayFormat = ',0;-0'
      StoredValues = 1
    end
    object edt_maxmen: TdxCurrencyEdit
      Left = 397
      Top = 82
      Width = 40
      TabOrder = 34
      Alignment = taRightJustify
      DecimalPlaces = 0
      DisplayFormat = ',0;-0'
      StoredValues = 1
    end
    object edt_maxmay: TdxCurrencyEdit
      Left = 397
      Top = 105
      Width = 40
      TabOrder = 35
      Alignment = taRightJustify
      DecimalPlaces = 0
      DisplayFormat = ',0;-0'
      StoredValues = 1
    end
    object DBEdit13: TDBEdit
      Left = 51
      Top = 152
      Width = 361
      Height = 21
      DataField = 'DESCRI'
      DataSource = dts_catprodsat
      TabOrder = 36
    end
    object DBEdit14: TDBEdit
      Left = 412
      Top = 152
      Width = 100
      Height = 21
      DataField = 'CODIGO'
      DataSource = dts_catprodsat
      TabOrder = 37
    end
    object edt_inioferta: TEdit
      Left = 706
      Top = 106
      Width = 75
      Height = 21
      PopupMenu = PopupMenu1
      TabOrder = 38
    end
    object edt_finoferta: TEdit
      Left = 706
      Top = 129
      Width = 75
      Height = 21
      PopupMenu = PopupMenu1
      TabOrder = 39
    end
    object edt_mubofert: TdxCurrencyEdit
      Left = 706
      Top = 152
      Width = 75
      PopupMenu = PopupMenu1
      Style.ButtonStyle = btsDefault
      Style.Edges = [edgLeft, edgTop, edgRight, edgBottom]
      TabOrder = 40
      Alignment = taRightJustify
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object edt_mubfilial: TdxCurrencyEdit
      Left = 706
      Top = 59
      Width = 75
      Style.ButtonStyle = btsDefault
      Style.Edges = [edgLeft, edgTop, edgRight, edgBottom]
      TabOrder = 41
      Alignment = taRightJustify
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object edt_proutlet: TdxCurrencyEdit
      Left = 856
      Top = 83
      Width = 75
      PopupMenu = PopupMenu1
      TabOrder = 42
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_inioutlet: TEdit
      Left = 856
      Top = 106
      Width = 75
      Height = 21
      PopupMenu = PopupMenu1
      TabOrder = 43
    end
    object edt_finoutlet: TEdit
      Left = 856
      Top = 129
      Width = 75
      Height = 21
      PopupMenu = PopupMenu1
      TabOrder = 44
    end
    object edt_muboutlet: TdxCurrencyEdit
      Left = 856
      Top = 151
      Width = 75
      PopupMenu = PopupMenu1
      Style.ButtonStyle = btsDefault
      Style.Edges = [edgLeft, edgTop, edgRight, edgBottom]
      TabOrder = 45
      Alignment = taRightJustify
      DisplayFormat = '0.00;-0.00'
      StoredValues = 1
    end
    object edt_servicio: TdxCurrencyEdit
      Left = 1009
      Top = 59
      Width = 75
      TabOrder = 46
      Alignment = taRightJustify
      StoredValues = 1
    end
    object edt_proferta: TEdit
      Left = 706
      Top = 83
      Width = 75
      Height = 21
      PopupMenu = PopupMenu1
      TabOrder = 47
    end
  end
  object sgrd_tarjeta: TAdvStringGrid
    Left = 0
    Top = 233
    Width = 1091
    Height = 70
    Align = alTop
    ColCount = 12
    DefaultRowHeight = 21
    FixedCols = 1
    RowCount = 3
    FixedRows = 1
    TabOrder = 1
    Bands.Active = True
    Bands.PrimaryColor = clInfoBk
    Bands.PrimaryLength = 1
    Bands.SecondaryColor = clWindow
    Bands.SecondaryLength = 1
    Bands.Print = False
    AutoNumAlign = True
    AutoSize = False
    VAlignment = vtaTop
    EnhTextSize = False
    EnhRowColMove = False
    SortFixedCols = False
    SortNormalCellsOnly = False
    SizeWithForm = False
    Multilinecells = False
    SortDirection = sdAscending
    SortFull = True
    SortAutoFormat = True
    SortShow = False
    SortIndexShow = False
    EnableGraphics = False
    EnableHTML = True
    EnableWheel = True
    Flat = False
    SortColumn = 0
    HintColor = clYellow
    SelectionColor = clHighlight
    SelectionTextColor = clHighlightText
    SelectionRectangle = False
    SelectionRTFKeep = False
    HintShowCells = False
    HintShowLargeText = False
    OleAcceptFiles = True
    OleAcceptText = True
    PrintSettings.FooterSize = 0
    PrintSettings.HeaderSize = 0
    PrintSettings.Time = ppNone
    PrintSettings.Date = ppNone
    PrintSettings.DateFormat = 'dd/mm/yyyy'
    PrintSettings.PageNr = ppNone
    PrintSettings.Title = ppNone
    PrintSettings.Font.Charset = DEFAULT_CHARSET
    PrintSettings.Font.Color = clWindowText
    PrintSettings.Font.Height = -11
    PrintSettings.Font.Name = 'MS Sans Serif'
    PrintSettings.Font.Style = []
    PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
    PrintSettings.HeaderFont.Color = clWindowText
    PrintSettings.HeaderFont.Height = -11
    PrintSettings.HeaderFont.Name = 'MS Sans Serif'
    PrintSettings.HeaderFont.Style = []
    PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
    PrintSettings.FooterFont.Color = clWindowText
    PrintSettings.FooterFont.Height = -11
    PrintSettings.FooterFont.Name = 'MS Sans Serif'
    PrintSettings.FooterFont.Style = []
    PrintSettings.Borders = pbNoborder
    PrintSettings.BorderStyle = psSolid
    PrintSettings.Centered = False
    PrintSettings.RepeatFixedRows = False
    PrintSettings.RepeatFixedCols = False
    PrintSettings.LeftSize = 0
    PrintSettings.RightSize = 0
    PrintSettings.ColumnSpacing = 0
    PrintSettings.RowSpacing = 0
    PrintSettings.TitleSpacing = 0
    PrintSettings.Orientation = poPortrait
    PrintSettings.FixedWidth = 0
    PrintSettings.FixedHeight = 0
    PrintSettings.UseFixedHeight = False
    PrintSettings.UseFixedWidth = False
    PrintSettings.FitToPage = fpNever
    PrintSettings.PageNumSep = '/'
    PrintSettings.NoAutoSize = False
    PrintSettings.PrintGraphics = False
    HTMLSettings.Width = 100
    Navigation.AllowInsertRow = False
    Navigation.AllowDeleteRow = False
    Navigation.AdvanceOnEnter = False
    Navigation.AdvanceInsert = False
    Navigation.AutoGotoWhenSorted = False
    Navigation.AutoGotoIncremental = False
    Navigation.AutoComboDropSize = False
    Navigation.AdvanceDirection = adLeftRight
    Navigation.AllowClipboardShortCuts = False
    Navigation.AllowSmartClipboard = False
    Navigation.AllowRTFClipboard = False
    Navigation.AllowClipboardAlways = False
    Navigation.AllowClipboardRowGrow = True
    Navigation.AllowClipboardColGrow = True
    Navigation.AdvanceAuto = False
    Navigation.InsertPosition = pInsertBefore
    Navigation.CursorWalkEditor = False
    Navigation.MoveRowOnSort = False
    Navigation.ImproveMaskSel = False
    Navigation.AlwaysEdit = False
    Navigation.CopyHTMLTagsToClipboard = True
    Navigation.LineFeedOnEnter = False
    ColumnSize.Save = False
    ColumnSize.Stretch = True
    ColumnSize.Location = clRegistry
    CellNode.Color = clSilver
    CellNode.NodeType = cnFlat
    CellNode.NodeColor = clBlack
    SizeWhileTyping.Height = False
    SizeWhileTyping.Width = False
    MaxEditLength = 0
    MouseActions.AllSelect = False
    MouseActions.ColSelect = False
    MouseActions.RowSelect = False
    MouseActions.DirectEdit = False
    MouseActions.DirectComboDrop = False
    MouseActions.DisjunctRowSelect = False
    MouseActions.AllColumnSize = False
    MouseActions.AllRowSize = False
    MouseActions.CaretPositioning = False
    IntelliPan = ipVertical
    URLColor = clBlue
    URLShow = False
    URLFull = False
    URLEdit = False
    ScrollType = ssNormal
    ScrollColor = clNone
    ScrollWidth = 16
    ScrollSynch = False
    ScrollProportional = False
    ScrollHints = shNone
    OemConvert = False
    FixedFooters = 0
    FixedRightCols = 0
    FixedColWidth = 24
    FixedRowHeight = 21
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'MS Sans Serif'
    FixedFont.Style = []
    FixedAsButtons = False
    FloatFormat = '%.2f'
    WordWrap = False
    ColumnHeaders.Strings = (
      ''
      'Inicia'
      'Compra'
      'Cancel'
      'Entran'
      'Tot.Ent.'
      'Sal.Vta'
      'Sal.Fon'
      'Salidas'
      'Sal.May'
      'Exist')
    Lookup = False
    LookupCaseSensitive = False
    LookupHistory = False
    BackGround.Top = 0
    BackGround.Left = 0
    BackGround.Display = bdTile
    BackGround.Cells = bcNormal
    Filter = <>
    ColWidths = (
      24
      36
      51
      44
      56
      64
      64
      64
      64
      64
      63
      481)
    RowHeights = (
      21
      21
      21)
  end
  object sgrd_exist: TAdvStringGrid
    Left = 0
    Top = 303
    Width = 1091
    Height = 50
    Align = alTop
    ColCount = 24
    DefaultColWidth = 25
    DefaultRowHeight = 21
    FixedCols = 0
    RowCount = 2
    FixedRows = 1
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
    TabOrder = 2
    Bands.Active = True
    Bands.PrimaryColor = clInfoBk
    Bands.PrimaryLength = 1
    Bands.SecondaryColor = clWindow
    Bands.SecondaryLength = 1
    Bands.Print = False
    AutoNumAlign = True
    AutoSize = False
    VAlignment = vtaTop
    EnhTextSize = False
    EnhRowColMove = False
    SortFixedCols = False
    SortNormalCellsOnly = False
    SizeWithForm = False
    Multilinecells = False
    SortDirection = sdAscending
    SortFull = True
    SortAutoFormat = True
    SortShow = False
    SortIndexShow = False
    EnableGraphics = False
    EnableHTML = True
    EnableWheel = True
    Flat = False
    SortColumn = 0
    HintColor = clYellow
    SelectionColor = clHighlight
    SelectionTextColor = clHighlightText
    SelectionRectangle = False
    SelectionRTFKeep = False
    HintShowCells = False
    HintShowLargeText = False
    OleAcceptFiles = True
    OleAcceptText = True
    PrintSettings.FooterSize = 0
    PrintSettings.HeaderSize = 0
    PrintSettings.Time = ppNone
    PrintSettings.Date = ppNone
    PrintSettings.DateFormat = 'dd/mm/yyyy'
    PrintSettings.PageNr = ppNone
    PrintSettings.Title = ppNone
    PrintSettings.Font.Charset = DEFAULT_CHARSET
    PrintSettings.Font.Color = clWindowText
    PrintSettings.Font.Height = -11
    PrintSettings.Font.Name = 'MS Sans Serif'
    PrintSettings.Font.Style = []
    PrintSettings.HeaderFont.Charset = DEFAULT_CHARSET
    PrintSettings.HeaderFont.Color = clWindowText
    PrintSettings.HeaderFont.Height = -11
    PrintSettings.HeaderFont.Name = 'MS Sans Serif'
    PrintSettings.HeaderFont.Style = []
    PrintSettings.FooterFont.Charset = DEFAULT_CHARSET
    PrintSettings.FooterFont.Color = clWindowText
    PrintSettings.FooterFont.Height = -11
    PrintSettings.FooterFont.Name = 'MS Sans Serif'
    PrintSettings.FooterFont.Style = []
    PrintSettings.Borders = pbNoborder
    PrintSettings.BorderStyle = psSolid
    PrintSettings.Centered = False
    PrintSettings.RepeatFixedRows = False
    PrintSettings.RepeatFixedCols = False
    PrintSettings.LeftSize = 0
    PrintSettings.RightSize = 0
    PrintSettings.ColumnSpacing = 0
    PrintSettings.RowSpacing = 0
    PrintSettings.TitleSpacing = 0
    PrintSettings.Orientation = poPortrait
    PrintSettings.FixedWidth = 0
    PrintSettings.FixedHeight = 0
    PrintSettings.UseFixedHeight = False
    PrintSettings.UseFixedWidth = False
    PrintSettings.FitToPage = fpNever
    PrintSettings.PageNumSep = '/'
    PrintSettings.NoAutoSize = False
    PrintSettings.PrintGraphics = False
    HTMLSettings.Width = 100
    Navigation.AllowInsertRow = False
    Navigation.AllowDeleteRow = False
    Navigation.AdvanceOnEnter = False
    Navigation.AdvanceInsert = False
    Navigation.AutoGotoWhenSorted = False
    Navigation.AutoGotoIncremental = False
    Navigation.AutoComboDropSize = False
    Navigation.AdvanceDirection = adLeftRight
    Navigation.AllowClipboardShortCuts = False
    Navigation.AllowSmartClipboard = False
    Navigation.AllowRTFClipboard = False
    Navigation.AllowClipboardAlways = False
    Navigation.AllowClipboardRowGrow = True
    Navigation.AllowClipboardColGrow = True
    Navigation.AdvanceAuto = False
    Navigation.InsertPosition = pInsertBefore
    Navigation.CursorWalkEditor = False
    Navigation.MoveRowOnSort = False
    Navigation.ImproveMaskSel = False
    Navigation.AlwaysEdit = False
    Navigation.CopyHTMLTagsToClipboard = True
    Navigation.LineFeedOnEnter = False
    ColumnSize.Save = False
    ColumnSize.Stretch = True
    ColumnSize.Location = clRegistry
    CellNode.Color = clSilver
    CellNode.NodeType = cnFlat
    CellNode.NodeColor = clBlack
    SizeWhileTyping.Height = False
    SizeWhileTyping.Width = False
    MaxEditLength = 0
    MouseActions.AllSelect = False
    MouseActions.ColSelect = False
    MouseActions.RowSelect = False
    MouseActions.DirectEdit = False
    MouseActions.DirectComboDrop = False
    MouseActions.DisjunctRowSelect = False
    MouseActions.AllColumnSize = False
    MouseActions.AllRowSize = False
    MouseActions.CaretPositioning = False
    IntelliPan = ipVertical
    URLColor = clBlue
    URLShow = False
    URLFull = False
    URLEdit = False
    ScrollType = ssNormal
    ScrollColor = clNone
    ScrollWidth = 16
    ScrollSynch = False
    ScrollProportional = False
    ScrollHints = shNone
    OemConvert = False
    FixedFooters = 0
    FixedRightCols = 0
    FixedColWidth = 25
    FixedRowHeight = 21
    FixedFont.Charset = DEFAULT_CHARSET
    FixedFont.Color = clWindowText
    FixedFont.Height = -11
    FixedFont.Name = 'MS Sans Serif'
    FixedFont.Style = []
    FixedAsButtons = False
    FloatFormat = '%.2f'
    WordWrap = False
    Lookup = False
    LookupCaseSensitive = False
    LookupHistory = False
    BackGround.Top = 0
    BackGround.Left = 0
    BackGround.Display = bdTile
    BackGround.Cells = bcNormal
    Filter = <>
    ColWidths = (
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      25
      488)
    RowHeights = (
      21
      21)
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1091
    Height = 53
    ButtonHeight = 49
    Caption = 'ToolBar1'
    Images = dm.ImageList1
    TabOrder = 3
    object SpeedButton6: TSpeedButton
      Left = 0
      Top = 2
      Width = 49
      Height = 49
      Action = WindowClose1
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000000084000000840000FFFF0000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400000084000000840000FFFF0000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400000084000000840000FFFF000000000000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000840000008400000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400FFFF0000000084000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF000000000000008400FFFF0000FFFF00000000000000FFFF0000FFFF0000FF
        FF0000FFFF0000FFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object ToolButton2: TToolButton
      Left = 49
      Top = 2
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 4
      Style = tbsSeparator
    end
    object SpeedButton5: TSpeedButton
      Left = 57
      Top = 2
      Width = 49
      Height = 49
      Action = primero
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        000000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000FF0000000000000000000000
        000000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton4: TSpeedButton
      Left = 106
      Top = 2
      Width = 49
      Height = 49
      Action = anterior
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000FF0000000000FF00FF00FF00
        FF0000000000000000000000FF000000FF000000FF000000FF000000FF000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF0000000000000000000000FF000000FF000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000000000000000FF000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton3: TSpeedButton
      Left = 155
      Top = 2
      Width = 49
      Height = 49
      Action = siguiente
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF000000000000000000FF00FF00FF00FF00000000000000
        FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000000000000000000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton2: TSpeedButton
      Left = 204
      Top = 2
      Width = 49
      Height = 49
      Action = ultimo
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF000000000000000000000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF0000000000000000000000000000000000000000000000
        FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000FF000000FF000000FF000000FF000000000000000000000000000000
        000000000000000000000000000000000000000000000000FF000000FF000000
        FF000000FF000000FF0000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000FF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000}
      Layout = blGlyphTop
    end
    object SpeedButton1: TSpeedButton
      Left = 253
      Top = 2
      Width = 49
      Height = 49
      Action = selec_orden
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000000000FFFF000000000000FF00FF00FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF00FF000000FF000000FFFFFF00FF000000FF000000FF00FF000000
        0000FFFF0000FFFF0000FFFF000000000000FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF00FF000000FF000000FFFFFF00FF000000FF00000000000000FFFF
        0000FFFF0000FFFF000000000000000000000000000000000000FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FF000000FF000000FFFFFF00FFFF0000FFFF
        0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FF000000FF000000FFFFFF0000000000FFFF
        00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF00FFFFFF00FF000000FF000000FFFFFF00FFFFFF00FF00FF000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
        FF0000000000FFFFFF00FF000000FF000000FFFFFF00FFFFFF00FF00FF000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000000000FF
        FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00FF000000
        000000FFFF000000000000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
        0000000000000000000000000000000000000000000000000000FF00FF000000
        0000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFFFF0000FF
        FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00FF00FF00
        FF000000000000000000FF00FF000000000000FFFF00FFFFFF0000000000FFFF
        FF0000000000FFFFFF00FFFFFF00FFFFFF000000FF000000FF00FF000000FF00
        0000FF00FF00FF00FF00FF00FF00FF00FF000000000000FFFF00FFFFFF000000
        000000000000FFFFFF00FFFFFF00FFFFFF000000FF000000FF00FF000000FF00
        00000000FF000000FF00FF00FF00FF00FF00FF00FF0000000000000000000000
        00000000FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF00FF00FF00FF00
        FF000000FF000000FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF000000
        FF000000FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF000000FF000000
        FF00FF00FF00FF000000FF000000FF00FF00FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF000000FF000000FF00FFFFFF000000FF000000FF000000FF000000
        FF00FF00FF00FF000000FF000000FF00FF00FF00FF0000000000FFFFFF00FFFF
        FF00FFFFFF000000FF000000FF00FFFFFF000000FF000000FF00}
      Layout = blGlyphTop
    end
    object SpeedButton8: TSpeedButton
      Left = 302
      Top = 2
      Width = 49
      Height = 49
      Action = nuevo_articulo
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF0000FF
        FF0000FFFF00FF00FF007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF007B7B
        7B007B7B7B007B7B7B007B7B7B0000FFFF0000FFFF00FF00FF00FF00FF00FF00
        FF0000FFFF000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00000000007B7B7B00FF00FF00FF00FF0000FFFF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF00FF00FF00FF00FF0000FF
        FF0000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000FFFF0000FFFF0000FFFF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF0000FFFF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF0000FF
        FF0000FFFF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF0000FFFF0000FFFF00FF00FF0000FFFF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000FFFF00}
      Layout = blGlyphTop
    end
    object SpeedButton9: TSpeedButton
      Left = 351
      Top = 2
      Width = 49
      Height = 49
      Action = modif_articulo
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        0000FF00FF000000000000000000000000000000000000000000FFFFFF00FFFF
        FF0000000000FFFFFF000000000000000000FFFFFF0000000000FFFF00000000
        00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
        0000FFFFFF000000000000000000FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
        00000000000000FFFF0000000000FFFFFF00FFFFFF0000000000FFFF00000000
        0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FF
        FF00FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFF00000000
        000000FFFF00FFFFFF0000000000000000000000000000000000000000000000
        000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
        00000000000000FFFF00FFFFFF0000FFFF00000000000000000000FFFF000000
        0000FFFFFF00FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000000000000000000000000000FFFF0000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF000000000000FFFF0000000000FFFFFF00FFFFFF000000
        000000000000FFFFFF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00
        FF00FF00FF000000000000FFFF000000000000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00
        FF00000000000000FF0000000000FF00FF0000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FF00FF00FF00FF000000000000000000000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object SpeedButton10: TSpeedButton
      Left = 400
      Top = 2
      Width = 49
      Height = 49
      Action = modif_ctorep
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF00FFFFFF007F7F7F000000000000000000000000007F7F
        7F00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF0000000000BFBFBF00FFFFFF00FFFFFF00FFFFFF00BFBF
        BF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF007F7F7F00BFBFBF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00BFBFBF007F7F7F00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF000000FF00000000000000
        0000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FFFFFF00FFFF
        FF00FFFFFF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF007F7F7F00BFBFBF00FFFFFF00FFFFFF0000000000FFFFFF00FFFF
        FF00BFBFBF007F7F7F00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF0000000000BFBFBF00FFFFFF0000000000FFFFFF00BFBF
        BF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF00FFFFFF007F7F7F000000000000000000000000007F7F
        7F00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF0000000000000000000000000000000000FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
        00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF000000
        0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
    object btn_ofertas: TSpeedButton
      Left = 449
      Top = 2
      Width = 49
      Height = 49
      Action = desplegar_ofertas
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF000000000000000000000000000000000000000000000000000000
        000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00000000000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
        00000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
        FF00000000000000800000000000FF00FF00FF00FF00FF00FF00000000000000
        0000000080000000800000008000000080000000800000008000000080000000
        800000000000000080000000800000000000FF00FF00FF00FF00000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000080000000800000000000FF00FF00FF00FF000000
        00007F7F7F0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF0000000000FFFFFF0000000000000080000000800000000000FF00FF00FF00
        FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF0000000000FFFFFF0000000000000000000000800000000000FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF007F7F7F0000000000000000000000
        000000000000FFFFFF0000000000FFFFFF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00000000000000000000000000FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FFFFFF000000000000000000FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF007F7F7F000000
        0000000000000000000000000000FFFFFF0000000000FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000000000000000FFFF
        FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF00FFFF
        FF007F7F7F0000000000000000000000000000000000FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00000000000000
        000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      Layout = blGlyphTop
    end
  end
  object page_detalles: TPageControl
    Left = 0
    Top = 356
    Width = 1091
    Height = 198
    ActivePage = tbs_kardex
    Align = alClient
    TabOrder = 4
    OnChange = page_detallesChange
    object tbs_kardex: TTabSheet
      Caption = '&Kardex'
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 1083
        Height = 23
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object Label17: TLabel
          Left = 5
          Top = 3
          Width = 41
          Height = 13
          Caption = 'Almacé&n'
          FocusControl = lkcmb_alm
        end
        object lkcmb_alm: TDBLookupComboBox
          Left = 51
          Top = 0
          Width = 86
          Height = 21
          DropDownWidth = 300
          KeyField = 'ALM'
          ListField = 'ALM; NOMBRE'
          ListSource = dts_almreps
          TabOrder = 0
          OnKeyUp = lkcmb_almKeyUp
        end
        object DBEdit12: TDBEdit
          Left = 140
          Top = 0
          Width = 435
          Height = 21
          Anchors = [akLeft, akTop, akRight]
          DataField = 'NOMBRE'
          DataSource = dts_almreps
          TabOrder = 1
          OnDblClick = DBEdit12DblClick
        end
        object btn_selalmactivos: TBitBtn
          Left = 400
          Top = -1
          Width = 257
          Height = 25
          Action = ver_almacenes
          Caption = 'Ver Almacenes Activos/Inactivos/Todos'
          TabOrder = 2
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0000000000FFFF000000000000FF00FF00FF00FF0000000000FFFFFF00FFFF
            FF00FFFFFF00FF000000FF000000FFFFFF00FF000000FF000000FF00FF000000
            0000FFFF0000FFFF0000FFFF000000000000FF00FF0000000000FFFFFF00FFFF
            FF00FFFFFF00FF000000FF000000FFFFFF00FF000000FF00000000000000FFFF
            0000FFFF0000FFFF000000000000000000000000000000000000FFFFFF00FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FF000000FF000000FFFFFF00FFFF0000FFFF
            0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFF
            FF00FFFFFF00FFFFFF00FFFFFF00FF000000FF000000FFFFFF0000000000FFFF
            00000000000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
            0000FFFFFF00FFFFFF00FF000000FF000000FFFFFF00FFFFFF00FF00FF000000
            000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFF
            FF0000000000FFFFFF00FF000000FF000000FFFFFF00FFFFFF00FF00FF000000
            0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF000000000000FF
            FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00FF000000
            000000FFFF000000000000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
            0000000000000000000000000000000000000000000000000000FF00FF000000
            0000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFFFF0000FF
            FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00FF00FF00
            FF000000000000000000FF00FF000000000000FFFF00FFFFFF0000000000FFFF
            FF0000000000FFFFFF00FFFFFF00FFFFFF000000FF000000FF00FF000000FF00
            0000FF00FF00FF00FF00FF00FF00FF00FF000000000000FFFF00FFFFFF000000
            000000000000FFFFFF00FFFFFF00FFFFFF000000FF000000FF00FF000000FF00
            00000000FF000000FF00FF00FF00FF00FF00FF00FF0000000000000000000000
            00000000FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF00FF00FF00FF00
            FF000000FF000000FF00FF00FF00FF00FF00FF00FF0000000000FFFFFF000000
            FF000000FF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF000000FF000000
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF0000000000FFFFFF00FFFF
            FF00FFFFFF000000FF000000FF00FFFFFF000000FF000000FF000000FF000000
            FF00FF00FF00FF000000FF000000FF00FF00FF00FF0000000000FFFFFF00FFFF
            FF00FFFFFF000000FF000000FF00FFFFFF000000FF000000FF00}
        end
      end
      object dbgrd_kardex: TdxDBGrid
        Left = 0
        Top = 23
        Width = 1083
        Height = 147
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'FOLIO'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 1
        OnDblClick = dbgrd_kardexDblClick
        OnKeyDown = dbgrd_kardexKeyDown
        DataSource = dts_movart
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_kardexCustomDrawCell
        object dbgrd_kardexFECHA: TdxDBGridDateColumn
          Caption = 'Fecha'
          Width = 70
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHA'
        end
        object dbgrd_kardexMODENT: TdxDBGridMaskColumn
          Caption = 'E'
          MinWidth = 15
          Width = 15
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MODENT'
          DisableFilter = True
        end
        object dbgrd_kardexNENTRADA: TdxDBGridMaskColumn
          Caption = 'Entrada'
          Width = 57
          BandIndex = 0
          RowIndex = 0
          FieldName = 'NENTRADA'
        end
        object dbgrd_kardexVIENEDE: TdxDBGridMaskColumn
          Caption = 'Viene de'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'VIENEDE'
        end
        object dbgrd_kardexFolviene: TdxDBGridMaskColumn
          Caption = 'Fol.Viene'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FOLVIENE'
        end
        object dbgrd_kardexProveedor: TdxDBGridColumn
          Caption = 'Proveedor'
          Width = 166
          BandIndex = 0
          RowIndex = 0
          FieldName = 'PROVE'
        end
        object dbgrd_kardexFOLIO: TdxDBGridMaskColumn
          Caption = 'Folio'
          Width = 45
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FOLIO'
        end
        object dbgrd_kardexSERIE: TdxDBGridMaskColumn
          Caption = 'Serie'
          Width = 81
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SERIE'
        end
        object dbgrd_kardexMODSAL: TdxDBGridMaskColumn
          Caption = 'S'
          MinWidth = 15
          Width = 15
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MODSAL'
          DisableFilter = True
        end
        object dbgrd_kardexfechsalida: TdxDBGridColumn
          Caption = 'F.Salida'
          Width = 65
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHASAL'
        end
        object dbgrd_kardexVahacia: TdxDBGridMaskColumn
          Caption = 'Recibe'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'VAHACIA'
        end
        object dbgrd_kardexFOLREC: TdxDBGridMaskColumn
          Caption = 'Folio Entra'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FOLREC'
        end
        object dbgrd_kardexComprador: TdxDBGridColumn
          Caption = 'Sale para'
          Width = 166
          BandIndex = 0
          RowIndex = 0
          FieldName = 'COMPRADOR'
        end
      end
    end
    object tbs_estadis: TTabSheet
      Caption = '&Estadísticas'
      ImageIndex = 1
      object dbgrd_estadis: TdxDBGrid
        Left = 0
        Top = 57
        Width = 1083
        Height = 113
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'ALM'
        ShowGroupPanel = True
        ShowSummaryFooter = True
        SummaryGroups = <
          item
            DefaultGroup = False
            SummaryItems = <
              item
                ColumnName = 'dbgrd_estadisENE'
                SummaryField = 'ENE'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisFEB'
                SummaryField = 'FEB'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisMAR'
                SummaryField = 'MAR'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisABR'
                SummaryField = 'ABR'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisMAY'
                SummaryField = 'MAY'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisJUN'
                SummaryField = 'JUN'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisJUL'
                SummaryField = 'JUL'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisAGO'
                SummaryField = 'AGO'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisSEP'
                SummaryField = 'SEP'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisOCT'
                SummaryField = 'OCT'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisNOV'
                SummaryField = 'NOV'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisDIC'
                SummaryField = 'DIC'
                SummaryFormat = '0'
                SummaryType = cstSum
              end
              item
                ColumnName = 'dbgrd_estadisTOT'
                SummaryField = 'TOT'
                SummaryFormat = '0'
                SummaryType = cstSum
              end>
            Name = 'dbgrd_estadisSummaryGroup2'
          end>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        DataSource = dts_estadis
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_kardexCustomDrawCell
        object dbgrd_estadisALM: TdxDBGridMaskColumn
          Caption = 'Alm'
          Width = 40
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ALM'
        end
        object dbgrd_estadisENE: TdxDBGridMaskColumn
          Caption = 'Ene'
          Width = 42
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ENE'
          SummaryFooterType = cstSum
          SummaryFooterField = 'ENE'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisFEB: TdxDBGridMaskColumn
          Caption = 'Feb'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FEB'
          SummaryFooterType = cstSum
          SummaryFooterField = 'FEB'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisMAR: TdxDBGridMaskColumn
          Caption = 'Mar'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MAR'
          SummaryFooterType = cstSum
          SummaryFooterField = 'MAR'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisABR: TdxDBGridMaskColumn
          Caption = 'Abr'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ABR'
          SummaryFooterType = cstSum
          SummaryFooterField = 'ABR'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisMAY: TdxDBGridMaskColumn
          Caption = 'May'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MAY'
          SummaryFooterType = cstSum
          SummaryFooterField = 'MAY'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisJUN: TdxDBGridMaskColumn
          Caption = 'Jun'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'JUN'
          SummaryFooterType = cstSum
          SummaryFooterField = 'JUN'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisJUL: TdxDBGridMaskColumn
          Caption = 'Jul'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'JUL'
          SummaryFooterType = cstSum
          SummaryFooterField = 'JUL'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisAGO: TdxDBGridMaskColumn
          Caption = 'Ago'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'AGO'
          SummaryFooterType = cstSum
          SummaryFooterField = 'AGO'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisSEP: TdxDBGridMaskColumn
          Caption = 'Sep'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SEP'
          SummaryFooterType = cstSum
          SummaryFooterField = 'SEP'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisOCT: TdxDBGridMaskColumn
          Caption = 'Oct'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'OCT'
          SummaryFooterType = cstSum
          SummaryFooterField = 'OCT'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisNOV: TdxDBGridMaskColumn
          Caption = 'Nov'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'NOV'
          SummaryFooterType = cstSum
          SummaryFooterField = 'NOV'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisDIC: TdxDBGridMaskColumn
          Caption = 'Dic'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'DIC'
          SummaryFooterType = cstSum
          SummaryFooterField = 'DIC'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisTOT: TdxDBGridMaskColumn
          Caption = 'Total'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'TOT'
          SummaryFooterType = cstSum
          SummaryFooterField = 'TOT'
          SummaryFooterFormat = '0'
        end
        object dbgrd_estadisNOMBRE: TdxDBGridMaskColumn
          Caption = 'Nombre'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'NOMBRE'
        end
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1083
        Height = 57
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 1
        object Splitter2: TSplitter
          Left = 441
          Top = 0
          Width = 3
          Height = 57
          Cursor = crHSplit
        end
        object Splitter3: TSplitter
          Left = 946
          Top = 0
          Width = 3
          Height = 57
          Cursor = crHSplit
          Align = alRight
        end
        object GroupBox3: TGroupBox
          Left = 444
          Top = 0
          Width = 502
          Height = 57
          Align = alClient
          TabOrder = 1
          object Label18: TLabel
            Left = 5
            Top = 12
            Width = 73
            Height = 13
            Caption = 'Estadísticas de'
          end
          object Label19: TLabel
            Left = 198
            Top = 12
            Width = 19
            Height = 13
            Caption = 'Año'
          end
          object cmb_tipoestadi: TComboBox
            Left = 83
            Top = 8
            Width = 103
            Height = 21
            Style = csDropDownList
            ItemHeight = 13
            TabOrder = 0
            Items.Strings = (
              'Salidas Especiales'
              'Salidas x Venta'
              'Entradas x Cancel'
              'Entradas Especiales'
              'Salidas Mayoreo'
              'Entradas x Compra')
          end
          object edt_anuestadis: TdxSpinEdit
            Left = 219
            Top = 8
            Width = 49
            TabOrder = 1
            OnDblClick = edt_anuestadisDblClick
            Alignment = taRightJustify
            Value = 1998
            StoredValues = 49
          end
        end
        object Panel4: TPanel
          Left = 949
          Top = 0
          Width = 134
          Height = 57
          Align = alRight
          BevelOuter = bvNone
          TabOrder = 2
          object btn_estadis: TBitBtn
            Left = 3
            Top = 6
            Width = 54
            Height = 25
            Caption = 'OK'
            ModalResult = 1
            TabOrder = 0
            OnClick = btn_estadisClick
            Glyph.Data = {
              DE010000424DDE01000000000000760000002800000024000000120000000100
              0400000000006801000000000000000000001000000000000000000000000000
              80000080000000808000800000008000800080800000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3333333333333333333333330000333333333333333333333333F33333333333
              00003333344333333333333333388F3333333333000033334224333333333333
              338338F3333333330000333422224333333333333833338F3333333300003342
              222224333333333383333338F3333333000034222A22224333333338F338F333
              8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
              33333338F83338F338F33333000033A33333A222433333338333338F338F3333
              0000333333333A222433333333333338F338F33300003333333333A222433333
              333333338F338F33000033333333333A222433333333333338F338F300003333
              33333333A222433333333333338F338F00003333333333333A22433333333333
              3338F38F000033333333333333A223333333333333338F830000333333333333
              333A333333333333333338330000333333333333333333333333333333333333
              0000}
            NumGlyphs = 2
          end
          object btn_estadiexp: TBitBtn
            Left = 63
            Top = 6
            Width = 64
            Height = 25
            Caption = 'Expert'
            TabOrder = 1
            OnClick = btn_estadiexpClick
            Kind = bkRetry
          end
        end
        object GroupBox2: TGroupBox
          Left = 0
          Top = 0
          Width = 441
          Height = 57
          Align = alLeft
          TabOrder = 0
          object llbl_estadisde: TLabel
            Left = 46
            Top = 11
            Width = 55
            Height = 13
            Caption = 'Agrupar por'
          end
          object lbl_estdiscod: TLabel
            Left = 186
            Top = 10
            Width = 64
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'Código'
          end
          object lbl_estadi2: TLabel
            Left = 186
            Top = 34
            Width = 64
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'Código'
          end
          object cmb_gpoestadis: TComboBox
            Left = 107
            Top = 9
            Width = 77
            Height = 21
            Style = csDropDownList
            ItemHeight = 13
            TabOrder = 0
            OnChange = cmb_gpoestadisChange
            Items.Strings = (
              'Grupo'
              'Marca'
              'Proveedor'
              'Situación'
              'Código'
              'Diary')
          end
          object cmb_estadi2: TComboBox
            Left = 107
            Top = 32
            Width = 77
            Height = 21
            Style = csDropDownList
            ItemHeight = 13
            TabOrder = 3
            OnChange = cmb_estadi2Change
            Items.Strings = (
              'Grupo'
              'Marca'
              'Proveedor'
              'Situación'
              'Código'
              'Diary')
          end
          object chk_estadis2: TCheckBox
            Left = 22
            Top = 34
            Width = 80
            Height = 17
            Caption = 'Además por'
            TabOrder = 2
            OnClick = chk_estadis2Click
          end
          object edt_codestadi2: TEdit
            Left = 258
            Top = 32
            Width = 180
            Height = 21
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            CharCase = ecUpperCase
            TabOrder = 4
          end
          object edt_codestad: TEdit
            Left = 258
            Top = 8
            Width = 180
            Height = 21
            Anchors = [akLeft, akTop, akRight]
            AutoSize = False
            CharCase = ecUpperCase
            TabOrder = 1
          end
        end
      end
    end
    object tbs_exist: TTabSheet
      Caption = 'E&xistencias'
      ImageIndex = 2
      object Panel3: TPanel
        Left = 0
        Top = 0
        Width = 1083
        Height = 33
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object GroupBox4: TGroupBox
          Left = 0
          Top = 0
          Width = 917
          Height = 33
          Align = alClient
          TabOrder = 0
          object lbl_exisgpo: TLabel
            Left = 272
            Top = 12
            Width = 67
            Height = 13
            Alignment = taRightJustify
            AutoSize = False
            Caption = 'Proveedor'
          end
          object Label20: TLabel
            Left = 8
            Top = 14
            Width = 72
            Height = 13
            Caption = 'Existencias Por'
          end
          object edt_gpoexi: TEdit
            Left = 342
            Top = 8
            Width = 105
            Height = 21
            TabOrder = 0
          end
          object cmb_tipoexis: TComboBox
            Left = 84
            Top = 9
            Width = 145
            Height = 21
            Style = csDropDownList
            ItemHeight = 13
            TabOrder = 1
            OnChange = cmb_tipoexisChange
            Items.Strings = (
              'Grupo'
              'Marca'
              'Proveedor'
              'Situación'
              'Código')
          end
        end
        object Panel5: TPanel
          Left = 917
          Top = 0
          Width = 166
          Height = 33
          Align = alRight
          BevelOuter = bvNone
          TabOrder = 1
          object btn_okxis: TBitBtn
            Left = 12
            Top = 6
            Width = 67
            Height = 25
            Caption = 'OK'
            ModalResult = 1
            TabOrder = 0
            OnClick = btn_okxisClick
            Glyph.Data = {
              DE010000424DDE01000000000000760000002800000024000000120000000100
              0400000000006801000000000000000000001000000000000000000000000000
              80000080000000808000800000008000800080800000C0C0C000808080000000
              FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
              3333333333333333333333330000333333333333333333333333F33333333333
              00003333344333333333333333388F3333333333000033334224333333333333
              338338F3333333330000333422224333333333333833338F3333333300003342
              222224333333333383333338F3333333000034222A22224333333338F338F333
              8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
              33333338F83338F338F33333000033A33333A222433333338333338F338F3333
              0000333333333A222433333333333338F338F33300003333333333A222433333
              333333338F338F33000033333333333A222433333333333338F338F300003333
              33333333A222433333333333338F338F00003333333333333A22433333333333
              3338F38F000033333333333333A223333333333333338F830000333333333333
              333A333333333333333338330000333333333333333333333333333333333333
              0000}
            NumGlyphs = 2
          end
          object btn_exiexpert: TBitBtn
            Left = 90
            Top = 6
            Width = 68
            Height = 25
            Caption = 'Expert'
            TabOrder = 1
            OnClick = btn_exiexpertClick
            Kind = bkRetry
          end
        end
      end
      object dbgrd_exist: TdxDBGrid
        Left = 0
        Top = 33
        Width = 1083
        Height = 137
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'CODIGO'
        ShowGroupPanel = True
        ShowSummaryFooter = True
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 1
        OnDblClick = dbgrd_existDblClick
        OnKeyDown = dbgrd_existKeyDown
        DataSource = dts_exigrid
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseLocate]
        OptionsView = [edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        ShowRowFooter = True
        OnCustomDrawCell = dbgrd_kardexCustomDrawCell
      end
    end
    object tbs_observs: TTabSheet
      Caption = '&Observaciones'
      ImageIndex = 3
      object dbgrd_observs: TdxDBGrid
        Left = 0
        Top = 0
        Width = 1083
        Height = 142
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'FECHA'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        DataSource = dts_observs
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_kardexCustomDrawCell
        object dbgrd_observsFECHA: TdxDBGridDateColumn
          Caption = 'Fecha'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHA'
        end
        object dbgrd_observsOBSERVS: TdxDBGridMaskColumn
          Caption = 'Observaciones'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'OBSERVS'
        end
      end
      object mmo_sql: TMemo
        Left = 0
        Top = 142
        Width = 1083
        Height = 28
        Align = alBottom
        Lines.Strings = (
          'mmo_sql')
        TabOrder = 1
        Visible = False
      end
    end
    object tbs_disponible: TTabSheet
      Caption = '&Disponibles'
      ImageIndex = 4
      OnShow = tbs_disponibleShow
      object dbgrd_dispo: TdxDBGrid
        Left = 0
        Top = 0
        Width = 1083
        Height = 170
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'SLLAVE'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        OnDblClick = dbgrd_dispoDblClick
        OnKeyDown = dbgrd_dispoKeyDown
        DataSource = dts_mvartdisp
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseBookmarks, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_kardexCustomDrawCell
        object dbgrd_dispoAlm: TdxDBGridColumn
          Caption = 'Alm'
          Width = 58
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ALM'
        end
        object dxDBGridFecha: TdxDBGridDateColumn
          Caption = 'Fecha'
          Width = 84
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHA'
        end
        object dxDBGridMODENT: TdxDBGridMaskColumn
          Caption = 'E'
          MinWidth = 15
          Width = 23
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MODENT'
          DisableFilter = True
        end
        object dxDBGridNENTRADA: TdxDBGridMaskColumn
          Caption = 'Entrada'
          Width = 87
          BandIndex = 0
          RowIndex = 0
          FieldName = 'NENTRADA'
        end
        object dbgrd_dispoVIENEDE: TdxDBGridMaskColumn
          Caption = 'Envia'
          Width = 51
          BandIndex = 0
          RowIndex = 0
          FieldName = 'VIENEDE'
        end
        object dbgrd_dispoFOLVIENE: TdxDBGridMaskColumn
          Caption = 'Folio Envia'
          Width = 89
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FOLVIENE'
        end
        object dxDBGridPROVE: TdxDBGridColumn
          Caption = 'Viende de'
          Width = 254
          BandIndex = 0
          RowIndex = 0
          FieldName = 'PROVE'
        end
        object dxDBGridFOLIO: TdxDBGridMaskColumn
          Caption = 'Folio'
          Width = 69
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FOLIO'
        end
        object dxDBGridSERIE: TdxDBGridMaskColumn
          Caption = 'Serie'
          Width = 115
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SERIE'
        end
        object dxDBGridMODSAL: TdxDBGridMaskColumn
          Caption = 'Status'
          MinWidth = 15
          Width = 39
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MODENT'
          DisableFilter = True
        end
        object dbgrd_dispoENTCAN: TdxDBGridMaskColumn
          Caption = 'Cancel'
          Width = 53
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ENTCAN'
        end
      end
    end
    object tbs_busserie: TTabSheet
      Caption = '&Busqueda Serie'
      ImageIndex = 5
      object Panel6: TPanel
        Left = 0
        Top = 0
        Width = 995
        Height = 24
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 0
        object Label21: TLabel
          Left = 8
          Top = 3
          Width = 69
          Height = 13
          Caption = 'Serie a Buscar'
        end
        object edt_busserie: TEdit
          Left = 88
          Top = 0
          Width = 121
          Height = 21
          CharCase = ecUpperCase
          TabOrder = 0
          OnKeyDown = edt_busserieKeyDown
        end
      end
      object dbgrd_busserie: TdxDBGrid
        Left = 0
        Top = 24
        Width = 995
        Height = 146
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'IDREG'
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 1
        OnDblClick = dbgrd_busserieDblClick
        OnKeyDown = dbgrd_busserieKeyDown
        DataSource = dts_seriebus
        Filter.Active = True
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoEnterShowEditor, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        OnCustomDrawCell = dbgrd_kardexCustomDrawCell
        object dxDBGridColumn1: TdxDBGridColumn
          Caption = 'Alm'
          Width = 38
          BandIndex = 0
          RowIndex = 0
          FieldName = 'ALM'
        end
        object dxDBGridDateColumn1: TdxDBGridDateColumn
          Caption = 'Fecha'
          Width = 55
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FECHA'
        end
        object dxDBGridMaskColumn1: TdxDBGridMaskColumn
          Caption = 'E'
          MinWidth = 15
          Width = 15
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MODENT'
          DisableFilter = True
        end
        object dxDBGridMaskColumn2: TdxDBGridMaskColumn
          Caption = 'Entrada'
          Width = 57
          BandIndex = 0
          RowIndex = 0
          FieldName = 'NENTRADA'
        end
        object dxDBGridColumn2: TdxDBGridColumn
          Caption = 'Viende de'
          Width = 166
          BandIndex = 0
          RowIndex = 0
          FieldName = 'PROVE'
        end
        object dxDBGridMaskColumn3: TdxDBGridMaskColumn
          Caption = 'Folio'
          Width = 45
          BandIndex = 0
          RowIndex = 0
          FieldName = 'FOLIO'
        end
        object dxDBGridMaskColumn4: TdxDBGridMaskColumn
          Caption = 'Serie'
          Width = 81
          BandIndex = 0
          RowIndex = 0
          FieldName = 'SERIE'
        end
        object dxDBGridMaskColumn5: TdxDBGridMaskColumn
          Caption = 'S'
          MinWidth = 15
          Width = 15
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MODSAL'
          DisableFilter = True
        end
        object dxDBGridColumn3: TdxDBGridColumn
          Caption = 'F.Salida'
          Width = 59
          BandIndex = 0
          RowIndex = 0
          FieldName = 'fechsalida'
        end
        object dxDBGridColumn4: TdxDBGridColumn
          Caption = 'Sale Para'
          Width = 166
          BandIndex = 0
          RowIndex = 0
          FieldName = 'COMPRA'
        end
      end
    end
    object TabSheet1: TTabSheet
      Caption = 'Condiciones Vta Linea'
      ImageIndex = 6
      object dbgrd_obslin: TdxDBGrid
        Left = 0
        Top = 0
        Width = 898
        Height = 158
        Bands = <
          item
          end>
        DefaultLayout = True
        HeaderPanelRowCount = 1
        KeyField = 'CONSE'
        ShowGroupPanel = True
        SummaryGroups = <>
        SummarySeparator = ', '
        Align = alClient
        PopupMenu = PopupMenu1
        TabOrder = 0
        OnDblClick = dbgrd_existDblClick
        OnKeyDown = dbgrd_existKeyDown
        DataSource = dts_obslin
        Filter.AutoDataSetFilter = True
        Filter.Criteria = {00000000}
        OptionsBehavior = [edgoAutoSort, edgoDragScroll, edgoImmediateEditor, edgoMultiSort, edgoTabThrough, edgoVertThrough]
        OptionsDB = [edgoCancelOnExit, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoSyncSelection, edgoUseLocate]
        OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
        ShowRowFooter = True
        OnCustomDrawCell = dbgrd_kardexCustomDrawCell
        object dbgrd_obslinMOE: TdxDBGridMaskColumn
          Sorted = csUp
          Visible = False
          BandIndex = 0
          RowIndex = 0
          FieldName = 'MOE'
          GroupIndex = 0
        end
        object dbgrd_obslinCONSE: TdxDBGridMaskColumn
          Caption = 'Orden'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'CONSE'
        end
        object dbgrd_obslinOBSER: TdxDBGridMaskColumn
          Caption = 'Observaciones'
          BandIndex = 0
          RowIndex = 0
          FieldName = 'OBSER'
        end
      end
    end
    object tbs_observsneg: TTabSheet
      Caption = 'Observ.Negociacion'
      ImageIndex = 7
      object Splitter4: TSplitter
        Left = 329
        Top = 0
        Width = 3
        Height = 158
        Cursor = crHSplit
      end
      object Splitter5: TSplitter
        Left = 661
        Top = 0
        Width = 3
        Height = 158
        Cursor = crHSplit
      end
      object grp_obsnegxpro: TGroupBox
        Tag = 2
        Left = 332
        Top = 0
        Width = 329
        Height = 158
        Align = alLeft
        Caption = 'Negociaciones x Proveedor'
        TabOrder = 0
        object Panel8: TPanel
          Left = 2
          Top = 15
          Width = 325
          Height = 37
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object btn_obsnegprove: TBitBtn
            Tag = 2
            Left = 6
            Top = 6
            Width = 307
            Height = 25
            Caption = 'Ver Observaciones Negociacion'
            TabOrder = 0
            OnClick = btn_obsnegmarcaClick
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00000000000000000000000000FFFF
              FF0000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF000000
              000000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
              FF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF0000000000FFFFFF0000FFFF000000000000000000FFFFFF000000
              0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF0000000000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF
              FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FF
              FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
              0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
              FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFF00000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
              0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFF0000FFFF
              00000000000000FFFF00FFFFFF0000FFFF000000000000FFFF00FFFFFF0000FF
              FF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FFFF0000FFFF
              0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
              0000FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FFFF0000FFFF
              0000FFFF0000FFFF000000000000000000000000000000000000000000000000
              0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
          end
        end
        object dbgrd_observnegxpro: TdxDBGrid
          Left = 2
          Top = 52
          Width = 325
          Height = 104
          Bands = <
            item
            end>
          DefaultLayout = True
          HeaderPanelRowCount = 1
          KeyField = 'FECHA'
          SummaryGroups = <>
          SummarySeparator = ', '
          Align = alClient
          PopupMenu = PopupMenu1
          TabOrder = 1
          DataSource = dts_observnegxpro
          Filter.Active = True
          Filter.AutoDataSetFilter = True
          Filter.Criteria = {00000000}
          OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
          OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowAutoHeight, edgoRowSelect, edgoUseBitmap]
          OnCustomDrawCell = dbgrd_kardexCustomDrawCell
          object dxDBGridDateColumn3: TdxDBGridDateColumn
            Caption = 'Fecha'
            Width = 82
            BandIndex = 0
            RowIndex = 0
            FieldName = 'FECHA'
          end
          object dxDBGridMaskColumn7: TdxDBGridWrapperColumn
            Caption = 'Observaciones'
            Width = 239
            BandIndex = 0
            RowIndex = 0
            FieldName = 'OBSERVS'
          end
        end
      end
      object grp_obsnegxmca: TGroupBox
        Left = 0
        Top = 0
        Width = 329
        Height = 158
        Align = alLeft
        Caption = 'Negociaciones x Marca'
        TabOrder = 1
        object Panel9: TPanel
          Left = 2
          Top = 15
          Width = 325
          Height = 37
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object btn_obsnegmarca: TBitBtn
            Tag = 1
            Left = 6
            Top = 6
            Width = 307
            Height = 25
            Caption = 'Ver Observaciones Negociacion '
            TabOrder = 0
            OnClick = btn_obsnegmarcaClick
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00000000000000000000000000FFFF
              FF0000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF000000
              000000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
              FF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF0000000000FFFFFF0000FFFF000000000000000000FFFFFF000000
              0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF0000000000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF
              FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FF
              FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
              0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
              FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFF00000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
              0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFF0000FFFF
              00000000000000FFFF00FFFFFF0000FFFF000000000000FFFF00FFFFFF0000FF
              FF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FFFF0000FFFF
              0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
              0000FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FFFF0000FFFF
              0000FFFF0000FFFF000000000000000000000000000000000000000000000000
              0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
          end
        end
        object dbgrd_observnegxmca: TdxDBGrid
          Left = 2
          Top = 52
          Width = 325
          Height = 104
          Bands = <
            item
            end>
          DefaultLayout = True
          HeaderPanelRowCount = 1
          KeyField = 'FECHA'
          SummaryGroups = <>
          SummarySeparator = ', '
          Align = alClient
          PopupMenu = PopupMenu1
          TabOrder = 1
          DataSource = dts_observnegxmca
          Filter.Active = True
          Filter.AutoDataSetFilter = True
          Filter.Criteria = {00000000}
          OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
          OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowAutoHeight, edgoRowSelect, edgoUseBitmap]
          OnCustomDrawCell = dbgrd_kardexCustomDrawCell
          object dxDBGridDateColumn4: TdxDBGridDateColumn
            Caption = 'Fecha'
            Width = 72
            BandIndex = 0
            RowIndex = 0
            FieldName = 'FECHA'
          end
          object dxDBGridMaskColumn8: TdxDBGridWrapperColumn
            Caption = 'Observaciones'
            Width = 285
            BandIndex = 0
            RowIndex = 0
            FieldName = 'OBSERVS'
          end
        end
      end
      object grp_obsnegxcod: TGroupBox
        Left = 664
        Top = 0
        Width = 234
        Height = 158
        Align = alClient
        Caption = 'Negociaciones x Codigo'
        TabOrder = 2
        object Panel7: TPanel
          Left = 2
          Top = 15
          Width = 230
          Height = 37
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object btn_obsnegcodigo: TBitBtn
            Tag = 3
            Left = 6
            Top = 6
            Width = 307
            Height = 25
            Caption = 'Ver Observaciones Negociacion'
            TabOrder = 0
            OnClick = btn_obsnegmarcaClick
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00000000000000000000000000FFFF
              FF0000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF000000
              000000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
              FF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF0000000000FFFFFF0000FFFF000000000000000000FFFFFF000000
              0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF0000000000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF
              FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FF
              FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
              0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
              FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFF00000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
              0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFF0000FFFF
              00000000000000FFFF00FFFFFF0000FFFF000000000000FFFF00FFFFFF0000FF
              FF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FFFF0000FFFF
              0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
              0000FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FFFF0000FFFF
              0000FFFF0000FFFF000000000000000000000000000000000000000000000000
              0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
          end
        end
        object dbgrd_observnegxcod: TdxDBGrid
          Left = 2
          Top = 52
          Width = 230
          Height = 104
          Bands = <
            item
            end>
          DefaultLayout = True
          HeaderPanelRowCount = 1
          KeyField = 'FECHA'
          SummaryGroups = <>
          SummarySeparator = ', '
          Align = alClient
          PopupMenu = PopupMenu1
          TabOrder = 1
          DataSource = dts_observnegxcod
          Filter.Active = True
          Filter.AutoDataSetFilter = True
          Filter.Criteria = {00000000}
          OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
          OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowAutoHeight, edgoRowSelect, edgoUseBitmap]
          OnCustomDrawCell = dbgrd_kardexCustomDrawCell
          object dxDBGridDateColumn2: TdxDBGridDateColumn
            Caption = 'Fecha'
            Width = 71
            BandIndex = 0
            RowIndex = 0
            FieldName = 'FECHA'
          end
          object dxDBGridMaskColumn6: TdxDBGridWrapperColumn
            Caption = 'Observaciones'
            Width = 163
            BandIndex = 0
            RowIndex = 0
            FieldName = 'OBSERVS'
          end
        end
      end
    end
    object tbs_imagenes: TTabSheet
      Caption = 'Imágenes'
      ImageIndex = 8
      object Splitter6: TSplitter
        Left = 483
        Top = 0
        Width = 3
        Height = 170
        Cursor = crHSplit
        Align = alRight
      end
      object Panel10: TPanel
        Left = 486
        Top = 0
        Width = 597
        Height = 170
        Align = alRight
        BevelOuter = bvNone
        TabOrder = 0
        object Panel12: TPanel
          Left = 0
          Top = 0
          Width = 597
          Height = 32
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object BitBtn1: TBitBtn
            Left = 11
            Top = 6
            Width = 206
            Height = 25
            Action = ver_imagen_completa
            Caption = 'Ver Imagen En Nueva Ventana'
            TabOrder = 0
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
              FF0000FFFF0000FFFF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00
              FF0000FFFF0000FFFF00000000000000000000FFFF0000FFFF0000FFFF0000FF
              FF0000FFFF0000FFFF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00
              FF0000FFFF0000FFFF000000000000FFFF0000FFFF0000FFFF0000FFFF0000FF
              FF0000FFFF000000000000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00
              FF0000FFFF0000FFFF0000FFFF000000000000FFFF0000FFFF0000FFFF0000FF
              FF0000000000000000000000000000FFFF00FF00FF00FF00FF00FF00FF00FF00
              FF0000FFFF0000FFFF0000FFFF00000000000000000000FFFF0000FFFF000000
              00000000000000FFFF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00
              FF0000FFFF0000FFFF0000FFFF0000FFFF000000000000FFFF00000000000000
              000000FFFF0000FFFF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00
              FF0000FFFF0000FFFF0000FFFF0000FFFF0000000000000000000000000000FF
              FF0000FFFF0000FFFF0000FFFF0000FFFF00FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF0000FFFF0000000000000000000000000000FFFF
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF000000000000FFFF0000BFBFBF0000000000000000000000
              000000000000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF000000000000BFBFBF000000000000000000FFFF
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF0000FFFF0000000000000000000000000000FFFF
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF0000FFFF0000FFFF00000000000000000000FFFF
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000000000000000
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000000000000000
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00FF00FF00FF00
              FF00FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF
              0000FFFF0000FFFF0000FFFF0000FFFF0000FF00FF00FF00FF00}
          end
        end
      end
      object Panel11: TPanel
        Left = 0
        Top = 0
        Width = 483
        Height = 170
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 1
        inline Frame_imginven1: TFrame_imginven
          Width = 483
          Height = 170
          Align = alClient
          inherited Splitter1: TSplitter
            Left = 220
            Height = 170
          end
          inherited pnl_imagen: TPanel
            Width = 220
            Height = 170
            inherited grp_ajustaimg: TGroupBox
              Width = 149
            end
            inherited scroll_boximg: TScrollBox
              Width = 149
              Height = 122
            end
          end
          inherited grp_listasimagenes: TGroupBox
            Left = 223
            Height = 170
            inherited dbgrd_imagenes: TdxDBGrid
              Height = 141
              Filter.Criteria = {00000000}
            end
            inherited grp_fotosact: TGroupBox
              Top = 245
              inherited mmo_fotos_actualizadas: TMemo
                Lines.Strings = ()
              end
            end
          end
        end
      end
    end
    object tbs_observcomer: TTabSheet
      Caption = 'ObservsComercializacion'
      ImageIndex = 9
      object grp_obscomxmca: TGroupBox
        Left = 0
        Top = 0
        Width = 329
        Height = 170
        Align = alLeft
        Caption = 'Observaciones x Marca'
        TabOrder = 0
        object Panel13: TPanel
          Left = 2
          Top = 15
          Width = 325
          Height = 37
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object BitBtn2: TBitBtn
            Tag = 4
            Left = 6
            Top = 6
            Width = 307
            Height = 25
            Caption = 'Ver Observaciones Comercialización'
            TabOrder = 0
            OnClick = btn_obsnegmarcaClick
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00000000000000000000000000FFFF
              FF0000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF000000
              000000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
              FF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF0000000000FFFFFF0000FFFF000000000000000000FFFFFF000000
              0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF0000000000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF
              FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FF
              FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
              0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
              FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFF00000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
              0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFF0000FFFF
              00000000000000FFFF00FFFFFF0000FFFF000000000000FFFF00FFFFFF0000FF
              FF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FFFF0000FFFF
              0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
              0000FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FFFF0000FFFF
              0000FFFF0000FFFF000000000000000000000000000000000000000000000000
              0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
          end
        end
        object dbgrd_obscommca: TdxDBGrid
          Left = 2
          Top = 52
          Width = 325
          Height = 116
          Bands = <
            item
            end>
          DefaultLayout = True
          HeaderPanelRowCount = 1
          KeyField = 'FECHA'
          SummaryGroups = <>
          SummarySeparator = ', '
          Align = alClient
          PopupMenu = PopupMenu1
          TabOrder = 1
          DataSource = dts_obscommca
          Filter.Active = True
          Filter.AutoDataSetFilter = True
          Filter.Criteria = {00000000}
          OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
          OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowAutoHeight, edgoRowSelect, edgoUseBitmap]
          OnCustomDrawCell = dbgrd_kardexCustomDrawCell
          object dxDBGridDateColumn5: TdxDBGridDateColumn
            Caption = 'Fecha'
            Width = 61
            BandIndex = 0
            RowIndex = 0
            FieldName = 'FECHA'
          end
          object dxDBGridMaskColumn9: TdxDBGridWrapperColumn
            Caption = 'Observaciones'
            Width = 256
            BandIndex = 0
            RowIndex = 0
            FieldName = 'OBSERVS'
          end
        end
      end
      object grp_obscomxlin: TGroupBox
        Tag = 2
        Left = 329
        Top = 0
        Width = 329
        Height = 170
        Align = alLeft
        Caption = 'Observaciones x Linea'
        TabOrder = 1
        object Panel14: TPanel
          Left = 2
          Top = 15
          Width = 325
          Height = 37
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object BitBtn3: TBitBtn
            Tag = 5
            Left = 6
            Top = 6
            Width = 307
            Height = 25
            Caption = 'Ver Observaciones Comercialización'
            TabOrder = 0
            OnClick = btn_obsnegmarcaClick
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00000000000000000000000000FFFF
              FF0000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF000000
              000000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
              FF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF0000000000FFFFFF0000FFFF000000000000000000FFFFFF000000
              0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF0000000000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF
              FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FF
              FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
              0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
              FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFF00000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
              0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFF0000FFFF
              00000000000000FFFF00FFFFFF0000FFFF000000000000FFFF00FFFFFF0000FF
              FF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FFFF0000FFFF
              0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
              0000FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FFFF0000FFFF
              0000FFFF0000FFFF000000000000000000000000000000000000000000000000
              0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
          end
        end
        object dbgrd_obscomlin: TdxDBGrid
          Left = 2
          Top = 52
          Width = 325
          Height = 116
          Bands = <
            item
            end>
          DefaultLayout = True
          HeaderPanelRowCount = 1
          KeyField = 'FECHA'
          SummaryGroups = <>
          SummarySeparator = ', '
          Align = alClient
          PopupMenu = PopupMenu1
          TabOrder = 1
          DataSource = dts_obscomlin
          Filter.Active = True
          Filter.AutoDataSetFilter = True
          Filter.Criteria = {00000000}
          OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
          OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowAutoHeight, edgoRowSelect, edgoUseBitmap]
          OnCustomDrawCell = dbgrd_kardexCustomDrawCell
          object dxDBGridDateColumn6: TdxDBGridDateColumn
            Caption = 'Fecha'
            Width = 79
            BandIndex = 0
            RowIndex = 0
            FieldName = 'FECHA'
          end
          object dxDBGridMaskColumn10: TdxDBGridWrapperColumn
            Caption = 'Observaciones'
            Width = 242
            BandIndex = 0
            RowIndex = 0
            FieldName = 'OBSERVS'
          end
        end
      end
      object grp_obscomxgpo: TGroupBox
        Left = 658
        Top = 0
        Width = 425
        Height = 170
        Align = alClient
        Caption = 'Observaciones x Grupo'
        TabOrder = 2
        object Panel15: TPanel
          Left = 2
          Top = 15
          Width = 421
          Height = 37
          Align = alTop
          BevelOuter = bvNone
          TabOrder = 0
          object BitBtn4: TBitBtn
            Tag = 6
            Left = 6
            Top = 6
            Width = 307
            Height = 25
            Caption = 'Ver Observaciones Comercialización'
            TabOrder = 0
            OnClick = btn_obsnegmarcaClick
            Glyph.Data = {
              36040000424D3604000000000000360000002800000010000000100000000100
              2000000000000004000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000000000000000000000000000000000000000
              0000000000000000000000000000000000000000000000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00000000000000000000000000FFFF
              FF0000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF000000
              000000000000FFFFFF000000000000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
              FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF00FF00FF00FF00FF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFF
              FF000000000000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FF00
              FF00FF00FF0000000000FFFFFF0000FFFF000000000000000000FFFFFF000000
              0000FFFFFF0000000000FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00
              FF0000000000FFFFFF0000FFFF000000000000FFFF00FFFFFF0000000000FFFF
              FF0000FFFF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FF
              FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF0000FFFF000000
              0000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000000000000000
              0000FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFF
              FF00FFFFFF00FFFFFF0000000000000000000000000000000000FFFF00000000
              000000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000000000000000
              0000FFFFFF00FFFFFF0000000000FFFFFF00FFFFFF0000000000FFFF0000FFFF
              00000000000000FFFF00FFFFFF0000FFFF000000000000FFFF00FFFFFF0000FF
              FF0000000000FFFFFF0000000000FFFFFF0000000000FF00FF00FFFF0000FFFF
              0000FFFF00000000000000FFFF00FFFFFF0000FFFF00FFFFFF00000000000000
              0000FFFFFF00FFFFFF000000000000000000FF00FF00FF00FF00FFFF0000FFFF
              0000FFFF0000FFFF000000000000000000000000000000000000000000000000
              0000000000000000000000000000FF00FF00FF00FF00FF00FF00}
          end
        end
        object dbgrd_obscomgpo: TdxDBGrid
          Left = 2
          Top = 52
          Width = 421
          Height = 116
          Bands = <
            item
            end>
          DefaultLayout = True
          HeaderPanelRowCount = 1
          KeyField = 'FECHA'
          SummaryGroups = <>
          SummarySeparator = ', '
          Align = alClient
          PopupMenu = PopupMenu1
          TabOrder = 1
          DataSource = dts_obscomgpo
          Filter.Active = True
          Filter.AutoDataSetFilter = True
          Filter.Criteria = {00000000}
          OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
          OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowAutoHeight, edgoRowSelect, edgoUseBitmap]
          OnCustomDrawCell = dbgrd_kardexCustomDrawCell
          object dxDBGridDateColumn7: TdxDBGridDateColumn
            Caption = 'Fecha'
            Width = 84
            BandIndex = 0
            RowIndex = 0
            FieldName = 'FECHA'
          end
          object dxDBGridMaskColumn11: TdxDBGridWrapperColumn
            Caption = 'Observaciones'
            Width = 148
            BandIndex = 0
            RowIndex = 0
            FieldName = 'OBSERVS'
          end
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Datos Internet'
      ImageIndex = 10
      object Panel16: TPanel
        Left = 0
        Top = 0
        Width = 185
        Height = 170
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 0
        object BitBtn5: TBitBtn
          Left = 16
          Top = 16
          Width = 153
          Height = 25
          Action = ModificaDatosInternet
          Caption = 'Modificar Datos Internet'
          TabOrder = 0
          Glyph.Data = {
            36040000424D3604000000000000360000002800000010000000100000000100
            2000000000000004000000000000000000000000000000000000FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF008000000080000000FF00000080000000FF00
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF0080000000FF000000800000008000000080000000FF0000008000
            00008000000080000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF0080000000FF00000080000000008080000080800080000000800000008000
            0000800000008000000080000000FF00FF00FF00FF00FF00FF00FF00FF008000
            0000FF00000080000000FF000000008080000080800080000000FF0000008000
            0000FF000000800000000080800000808000FF00FF00FF00FF00FF00FF008000
            0000FF000000FF000000FF000000008080000080800000808000800000008000
            000080000000800000000080800000808000FF00FF00FF00FF00FF000000FF00
            0000FF000000FF000000FF000000008080000080800000808000FF000000FF00
            0000FF00000080000000FF0000008000000080000000FF00FF0080000000FF00
            0000FF0000000080800000808000008080000080800000808000FF000000FF00
            0000FF000000800000008000000080000000FF000000FF00FF00FF0000008000
            0000008080000080800000808000008080000080800000808000FF0000000080
            8000FF00000080000000FF000000FF000000FF000000FF00FF0080000000FF00
            0000FF0000000080800000808000008080000080800000808000008080000080
            800000808000FF00000080000000FF00000080000000FF00FF00FF000000FF00
            0000FF0000000080800000808000FF000000FF00000080000000008080000080
            800000808000FF000000FF00000080000000FF000000FF00FF00FF00FF00FF00
            0000FF000000FF000000FF000000FF0000000080800000808000008080000080
            8000008080000080800080000000FF000000FF00FF00FF00FF00FF00FF008000
            0000FF0000000080800000808000008080000080800000808000008080000080
            80000080800000808000FF000000FF000000FF00FF00FF00FF00FF00FF00FF00
            FF0000808000008080000080800000808000FF000000FF00000000808000FF00
            00000080800000808000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF000080800000808000FF000000FF00000080000000FF0000008000
            0000FF000000FF000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
            FF00FF00FF00FF00FF00FF00FF00FF00000080000000FF000000FF000000FF00
            0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
        end
      end
      inline Frame_datosinternet1: TFrame_datosinternet
        Left = 185
        Width = 898
        Height = 170
        Align = alClient
        TabOrder = 1
        inherited Panel1: TPanel
          Width = 898
        end
        inherited GroupBox1: TGroupBox
          Width = 898
          Height = 113
          inherited mmo_descripcion: TMemo
            Width = 894
            Height = 96
          end
        end
      end
    end
  end
  object qry_inven: TQuery
    OnCalcFields = qry_invenCalcFields
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select  a.* from inven a'
      'where a.codigo = :Codigo and a.cia = :Cia')
    Left = 600
    Top = 464
    ParamData = <
      item
        DataType = ftString
        Name = 'Codigo'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'cia'
        ParamType = ptUnknown
      end>
    object qry_invenCODIGO: TStringField
      FieldName = 'CODIGO'
      Origin = 'manvehi.INVEN.CODIGO'
      Size = 13
    end
    object qry_invenCOD2: TStringField
      FieldName = 'COD2'
      Origin = 'manvehi.INVEN.COD2'
      Size = 13
    end
    object qry_invenDESCRI: TStringField
      FieldName = 'DESCRI'
      Origin = 'manvehi.INVEN.DESCRI'
      Size = 30
    end
    object qry_invenTIPO: TStringField
      FieldName = 'TIPO'
      Origin = 'manvehi.INVEN.TIPO'
      Size = 3
    end
    object qry_invenPROVE: TStringField
      FieldName = 'PROVE'
      Origin = 'manvehi.INVEN.PROVE'
      Size = 4
    end
    object qry_invenLINEA: TStringField
      FieldName = 'LINEA'
      Origin = 'manvehi.INVEN.LINEA'
      Size = 4
    end
    object qry_invenEMPAQE: TStringField
      FieldName = 'EMPAQE'
      Origin = 'manvehi.INVEN.EMPAQE'
      Size = 10
    end
    object qry_invenMINIMO: TSmallintField
      FieldName = 'MINIMO'
      Origin = 'manvehi.INVEN.MINIMO'
      DisplayFormat = '#0'
    end
    object qry_invenMAXIMO: TSmallintField
      FieldName = 'MAXIMO'
      Origin = 'manvehi.INVEN.MAXIMO'
      DisplayFormat = '#0'
    end
    object qry_invenPRECIO: TFloatField
      FieldName = 'PRECIO'
      Origin = 'manvehi.INVEN.PRECIO'
      DisplayFormat = '###,##0.00'
    end
    object qry_invenPIVA: TFloatField
      FieldName = 'PIVA'
      Origin = 'manvehi.INVEN.PIVA'
    end
    object qry_invenCOSTOS: TFloatField
      FieldName = 'COSTOS'
      Origin = 'manvehi.INVEN.COSTOS'
      DisplayFormat = '###,##0.00'
    end
    object qry_invenCOSTON: TFloatField
      FieldName = 'COSTON'
      Origin = 'manvehi.INVEN.COSTON'
      DisplayFormat = '###,##0.00'
    end
    object qry_invenINICIALS: TFloatField
      FieldName = 'INICIALS'
      Origin = 'manvehi.INVEN.INICIALS'
    end
    object qry_invenENTCOMS: TFloatField
      FieldName = 'ENTCOMS'
      Origin = 'manvehi.INVEN.ENTCOMS'
    end
    object qry_invenENTCANS: TFloatField
      FieldName = 'ENTCANS'
      Origin = 'manvehi.INVEN.ENTCANS'
    end
    object qry_invenENTESPS: TFloatField
      FieldName = 'ENTESPS'
      Origin = 'manvehi.INVEN.ENTESPS'
    end
    object qry_invenSALVTAS: TFloatField
      FieldName = 'SALVTAS'
      Origin = 'manvehi.INVEN.SALVTAS'
    end
    object qry_invenSALFONS: TFloatField
      FieldName = 'SALFONS'
      Origin = 'manvehi.INVEN.SALFONS'
    end
    object qry_invenSALESPS: TFloatField
      FieldName = 'SALESPS'
      Origin = 'manvehi.INVEN.SALESPS'
    end
    object qry_invenSALMAYS: TFloatField
      FieldName = 'SALMAYS'
      Origin = 'manvehi.INVEN.SALMAYS'
    end
    object qry_invenEXISTES: TFloatField
      FieldName = 'EXISTES'
      Origin = 'manvehi.INVEN.EXISTES'
    end
    object qry_invenINICIALN: TFloatField
      FieldName = 'INICIALN'
      Origin = 'manvehi.INVEN.INICIALN'
    end
    object qry_invenENTCOMN: TFloatField
      FieldName = 'ENTCOMN'
      Origin = 'manvehi.INVEN.ENTCOMN'
    end
    object qry_invenENTCANN: TFloatField
      FieldName = 'ENTCANN'
      Origin = 'manvehi.INVEN.ENTCANN'
    end
    object qry_invenENTESPN: TFloatField
      FieldName = 'ENTESPN'
      Origin = 'manvehi.INVEN.ENTESPN'
    end
    object qry_invenSALVTAN: TFloatField
      FieldName = 'SALVTAN'
      Origin = 'manvehi.INVEN.SALVTAN'
    end
    object qry_invenSALFONN: TFloatField
      FieldName = 'SALFONN'
      Origin = 'manvehi.INVEN.SALFONN'
    end
    object qry_invenSALESPN: TFloatField
      FieldName = 'SALESPN'
      Origin = 'manvehi.INVEN.SALESPN'
    end
    object qry_invenSALMAYN: TFloatField
      FieldName = 'SALMAYN'
      Origin = 'manvehi.INVEN.SALMAYN'
    end
    object qry_invenEXISTEN: TFloatField
      FieldName = 'EXISTEN'
      Origin = 'manvehi.INVEN.EXISTEN'
    end
    object qry_invenCOSINICIALS: TFloatField
      FieldName = 'COSINICIALS'
      Origin = 'manvehi.INVEN.COSINICIALS'
    end
    object qry_invenCOSENTCOMS: TFloatField
      FieldName = 'COSENTCOMS'
      Origin = 'manvehi.INVEN.COSENTCOMS'
    end
    object qry_invenCOSENTCANS: TFloatField
      FieldName = 'COSENTCANS'
      Origin = 'manvehi.INVEN.COSENTCANS'
    end
    object qry_invenCOSENTESPS: TFloatField
      FieldName = 'COSENTESPS'
      Origin = 'manvehi.INVEN.COSENTESPS'
    end
    object qry_invenCOSSALVTAS: TFloatField
      FieldName = 'COSSALVTAS'
      Origin = 'manvehi.INVEN.COSSALVTAS'
    end
    object qry_invenCOSSALFONS: TFloatField
      FieldName = 'COSSALFONS'
      Origin = 'manvehi.INVEN.COSSALFONS'
    end
    object qry_invenCOSSALESPS: TFloatField
      FieldName = 'COSSALESPS'
      Origin = 'manvehi.INVEN.COSSALESPS'
    end
    object qry_invenCOSSALMAYS: TFloatField
      FieldName = 'COSSALMAYS'
      Origin = 'manvehi.INVEN.COSSALMAYS'
    end
    object qry_invenCOSEXISTES: TFloatField
      FieldName = 'COSEXISTES'
      Origin = 'manvehi.INVEN.COSEXISTES'
    end
    object qry_invenCOSINICIALN: TFloatField
      FieldName = 'COSINICIALN'
      Origin = 'manvehi.INVEN.COSINICIALN'
    end
    object qry_invenCOSENTCOMN: TFloatField
      FieldName = 'COSENTCOMN'
      Origin = 'manvehi.INVEN.COSENTCOMN'
    end
    object qry_invenCOSENTCANN: TFloatField
      FieldName = 'COSENTCANN'
      Origin = 'manvehi.INVEN.COSENTCANN'
    end
    object qry_invenCOSENTESPN: TFloatField
      FieldName = 'COSENTESPN'
      Origin = 'manvehi.INVEN.COSENTESPN'
    end
    object qry_invenCOSSALVTAN: TFloatField
      FieldName = 'COSSALVTAN'
      Origin = 'manvehi.INVEN.COSSALVTAN'
    end
    object qry_invenCOSSALFONN: TFloatField
      FieldName = 'COSSALFONN'
      Origin = 'manvehi.INVEN.COSSALFONN'
    end
    object qry_invenCOSSALESPN: TFloatField
      FieldName = 'COSSALESPN'
      Origin = 'manvehi.INVEN.COSSALESPN'
    end
    object qry_invenCOSSALMAYN: TFloatField
      FieldName = 'COSSALMAYN'
      Origin = 'manvehi.INVEN.COSSALMAYN'
    end
    object qry_invenCOSEXISTEN: TFloatField
      FieldName = 'COSEXISTEN'
      Origin = 'manvehi.INVEN.COSEXISTEN'
    end
    object qry_invenFECALTA: TDateField
      FieldName = 'FECALTA'
      Origin = 'manvehi.INVEN.FECALTA'
    end
    object qry_invenCIA: TSmallintField
      FieldName = 'CIA'
      Origin = 'manvehi.INVEN.CIA'
    end
    object qry_invenMDS: TStringField
      FieldName = 'MDS'
      Origin = 'manvehi.INVEN.MDS'
      Size = 1
    end
    object qry_invenELEC: TStringField
      FieldName = 'ELEC'
      Origin = 'manvehi.INVEN.ELEC'
      Size = 1
    end
    object qry_invenPRECELEC: TFloatField
      FieldName = 'PRECELEC'
      Origin = 'manvehi.INVEN.PRECELEC'
      DisplayFormat = '###,##0.00'
    end
    object qry_invenmubmds: TFloatField
      FieldKind = fkCalculated
      FieldName = 'mubmds'
      DisplayFormat = '#0.00'
      Calculated = True
    end
    object qry_invenmubelec: TFloatField
      FieldKind = fkCalculated
      FieldName = 'mubelec'
      DisplayFormat = '#0.00'
      Calculated = True
    end
    object qry_invenmaxi: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'maxi'
      DisplayFormat = '#0'
      Calculated = True
    end
  end
  object dts_inven: TDataSource
    DataSet = qry_inven
    Left = 600
    Top = 496
  end
  object qry_diary: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select c.grupo from inv_invhist a join inv_relinv b'
      'on a.idart = b.idart and b.idrel = :TIPOREL'
      'join gpodiary c on b.iddato = c.idgpodiary'
      'where a.codigo=:CODIGO and a.cia = :CIA')
    Left = 536
    Top = 464
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_diary: TDataSource
    DataSet = qry_diary
    Left = 536
    Top = 496
  end
  object qry_buscod: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'Select codigo,descri from inven where codigo like :CODIGO  and c' +
        'ia = :CIA'
      'and'
      '('
      '(existes + existen > :EXIMIN) or (existes + existen = :EXIMAX)'
      ')'
      'order by codigo'
      ''
      ' ')
    Left = 568
    Top = 464
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'EXIMIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'EXIMAX'
        ParamType = ptUnknown
      end>
  end
  object dts_buscod: TDataSource
    DataSet = qry_buscod
    Left = 568
    Top = 496
  end
  object qry_invulpre: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from invulpre'
      'where codigo = :CODIGO and fecha ='
      
        '( select max (fecha) from invulpre where codigo=:CODIGO and cia ' +
        '= :CIA)'
      'and cia = :CIA')
    Left = 504
    Top = 464
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_invulpre: TDataSource
    DataSet = qry_invulpre
    Left = 504
    Top = 496
  end
  object qry_exist: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave as alm, nombre, (existes + existen) as exis, ultfol'
      'from almacen a join exist b'
      
        'on (a.clave = b.alm and a.cia = b.cia) where codigo = :CODIGO an' +
        'd a.cia = :CIA'
      'order by ordiary, alm')
    Left = 472
    Top = 464
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_exist: TDataSource
    DataSet = qry_exist
    Left = 472
    Top = 496
  end
  object dts_alms: TDataSource
    DataSet = qry_alms
    Left = 440
    Top = 496
  end
  object qry_alms: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select clave as alm, nombre, status  from almacen where cia = :C' +
        'IA'
      'order by ordiary, clave')
    Left = 440
    Top = 464
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 944
    Top = 128
    object nuevo: TAction
      Caption = '&Nuevo'
      ImageIndex = 0
      ShortCut = 16462
      OnExecute = nuevoExecute
    end
    object modifica: TAction
      Caption = '&Modifica'
      Hint = 'Modifica'
      ImageIndex = 1
      ShortCut = 16461
      OnExecute = modificaExecute
    end
    object borra: TAction
      Caption = 'Borra'
      Hint = 'Borra'
      ImageIndex = 2
      ShortCut = 16450
      OnExecute = borraExecute
    end
    object grabar: TAction
      Caption = 'Grabar'
      ShortCut = 16449
      OnExecute = grabarExecute
    end
    object cancelar: TAction
      Caption = 'Cancelar'
      ShortCut = 16460
      OnExecute = cancelarExecute
    end
    object WindowClose1: TWindowClose
      Category = 'Window'
      Caption = 'C&lose'
      Hint = 'Termina la Sesión'
      ImageIndex = 3
    end
    object primero: TAction
      Caption = 'Primero'
      Hint = 'Selecciona al Primer Artículo'
      ImageIndex = 5
      ShortCut = 49232
      OnExecute = primeroExecute
    end
    object anterior: TAction
      Caption = 'Anterior'
      Hint = 'Selecciona al Anterior Artículo'
      ImageIndex = 6
      ShortCut = 49217
      OnExecute = anteriorExecute
    end
    object siguiente: TAction
      Caption = 'Siguiente'
      Hint = 'Selecciona al Siguiente Artículo'
      ImageIndex = 8
      ShortCut = 49235
      OnExecute = siguienteExecute
    end
    object ultimo: TAction
      Caption = 'Ultimo'
      Hint = 'Selecciona al Ultimo Artículo'
      ImageIndex = 7
      ShortCut = 49237
      OnExecute = ultimoExecute
    end
    object exporta_dbgrd: TAction
      Caption = 'Exportar a ...'
      ImageIndex = 19
      OnExecute = exporta_dbgrdExecute
    end
    object selec_orden: TAction
      Caption = 'Sel. Orden '
      Hint = 'Selecciona el Orden de avance de anterior y siguiente'
      ImageIndex = 29
      OnExecute = selec_ordenExecute
    end
    object graba_estadis_anual: TAction
      Caption = 'Grabar Estadis Anual'
      ImageIndex = 23
      OnExecute = graba_estadis_anualExecute
    end
    object cambia_serie: TAction
      Caption = 'Cambiar Serie'
      ImageIndex = 29
      OnExecute = cambia_serieExecute
    end
    object agrega_obsneg: TAction
      Caption = 'Agregar Eliminar y Modificar Observaciones'
      ImageIndex = 27
    end
    object despliega_cambios_precio: TAction
      Caption = 'Cambios de Precio'
      ImageIndex = 29
      OnExecute = despliega_cambios_precioExecute
    end
    object nuevo_articulo: TAction
      Caption = 'Agregar'
      ImageIndex = 0
      OnExecute = nuevo_articuloExecute
    end
    object modif_articulo: TAction
      Caption = 'Modificar'
      ImageIndex = 1
      OnExecute = modif_articuloExecute
    end
    object ver_imagen_completa: TAction
      Caption = 'Ver Imagen En Nueva Ventana'
      ImageIndex = 35
      OnExecute = ver_imagen_completaExecute
    end
    object ver_permision: TAction
      Caption = 'Permisiones'
      OnExecute = ver_permisionExecute
    end
    object ver_almacenes: TAction
      Caption = 'Ver Almacenes Activos/Inactivos/Todos'
      ImageIndex = 29
      OnExecute = ver_almacenesExecute
    end
    object modif_ctorep: TAction
      Caption = 'Cto.Repo'
      ImageIndex = 33
      Visible = False
      OnExecute = modif_ctorepExecute
    end
    object desplegar_ofertas: TAction
      Caption = 'Ofertas'
      ImageIndex = 23
      OnExecute = desplegar_ofertasExecute
    end
    object despliega_historico_costo_repo: TAction
      Caption = 'Desplegar Historico Costo Reposicion'
      ImageIndex = 37
      OnExecute = despliega_historico_costo_repoExecute
    end
    object ModificaDatosInternet: TAction
      Caption = 'Modificar Datos Internet'
      ImageIndex = 40
      OnExecute = ModificaDatosInternetExecute
    end
  end
  object qry_haciainv: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave as alm, nombre  from almacen where cia = :CIA '
      'order by ordiary, alm')
    Left = 408
    Top = 464
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_haciainv: TDataSource
    DataSet = qry_haciainv
    Left = 408
    Top = 496
  end
  object qry_marca: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select c.codigo from inv_invhist a join inv_relinv b'
      'on a.idart = b.idart and b.idrel = :TIPOREL'
      'join inv_marcas c on b.iddato = c.idmarcainv'
      'where a.codigo=:CODIGO and a.cia = :CIA'
      ' ')
    Left = 376
    Top = 464
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_marca: TDataSource
    DataSet = qry_marca
    Left = 376
    Top = 496
  end
  object qry_movart: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select codigo, fecha, folio, serie, almac as alm, costo,'
      'c.concepto as prove, modent, nentrada,'
      'vienede, '
      
        'cast( (case folviene when 0 then null else folviene end) as inte' +
        'ger) as folviene,'
      'salio, modsal, '
      
        'cast( (case salio when '#39'S'#39' then fechasal end) as date) as fechas' +
        'al,'
      'd.concepto as comprador,'
      'vahacia,'
      
        'cast( (case folrec when 0 then null else folrec end) as integer)' +
        ' as folrec'
      'from movart a'
      'left outer join conceps c on a.nompro = c.ncon'
      'left outer join conceps d on a.compro = d.ncon'
      'where a.codigo =  :CODIGO and a.almac = :ALM and a.cia = :CIA'
      'order by folio ')
    Left = 345
    Top = 464
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_movart: TDataSource
    DataSet = qry_movart
    Left = 345
    Top = 496
  end
  object qry_conceps: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select concepto, ncon from conceps where ncon = :IDCONCEPTO')
    Left = 314
    Top = 464
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDCONCEPTO'
        ParamType = ptUnknown
      end>
  end
  object qry_estadis: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select alm, NULL as Ene, NULL as Feb, NULL as Mar, NULL as Abr, ' +
        'NULL as May, NULL as Jun, '
      
        'NULL as Jul, NULL as Ago, NULL as Sep, NULL as Oct, NULL as Nov,' +
        ' NULL as Dic, 0 as Tot,'
      'cast('#39#39' as varchar(30) ) as nombre'
      'from estadis'
      'where '
      
        '(tipo= :TIPO1 or tipo = :TIPO2) and anu = :ANU and codigo = :COD' +
        'IGO and cia = :CIA'
      'group by alm')
    UpdateObject = uqry_estadis
    Left = 19
    Top = 432
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_estadis: TDataSource
    AutoEdit = False
    DataSet = qry_estadis
    Left = 19
    Top = 464
  end
  object uqry_estadis: TUpdateSQL
    Left = 20
    Top = 474
  end
  object qry_estadialm: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select alm, mes, sum(unidades) from estadis '
      'where (tipo = :TIPO1 or tipo = :TIPO2) '
      'and anu = :ANU and codigo = :CODIGO and cia=:CIA'
      'group by alm,mes')
    Left = 244
    Top = 385
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_exisgpo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select alm, mes, sum(unidades) from estadis '
      'where (tipo = :TIPO1 or tipo = :TIPO2) '
      'and anu = :ANU and codigo = :CODIGO and cia=:CIA'
      'group by alm,mes')
    Left = 212
    Top = 385
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_ordenalm: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select alm, id from ordenalm order by id, alm')
    Left = 440
    Top = 432
  end
  object qry_observs: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select * from observent where tipo= :TIPOOBS and alm = :ALM and ' +
        'codigo = :CODIGO and cia = :CIA and numero = :NUMERO'
      'order by fecha desc, conse'
      ' ')
    Left = 182
    Top = 385
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end>
  end
  object dts_observs: TDataSource
    AutoEdit = False
    DataSet = qry_observs
    Left = 179
    Top = 416
  end
  object qry_exigrid: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.codigo, descri, alm, (a.existes + a.existen) as exist, ' +
        'coston  from inven a join exist b on a.codigo=b.codigo '
      'and a.cia = b.cia'
      'and rownum < 10')
    UpdateObject = uqry_exigrid
    Left = 852
    Top = 449
  end
  object dts_exigrid: TDataSource
    AutoEdit = False
    DataSet = qry_exigrid
    Left = 852
    Top = 418
  end
  object uqry_exigrid: TUpdateSQL
    Left = 852
    Top = 481
  end
  object qry_mvartdisp: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select (codigo||almac||cast(folio as varchar(10) ) ) as sllave,'
      'codigo, fecha, folio, serie, almac as alm, costo, exib, ordiary,'
      'c.concepto as prove, modent, nentrada,'
      'vienede, folviene, entcan,'
      'salio, modsal, cast (null as date) as fechasal,'
      'cast ( null as varchar(30)) as comprador,'
      'cast ( null as varchar(4) ) as vahacia,'
      'cast ( null as integer) as folrec,'
      'cast ( a.nompro + folio as integer) as idreg'
      'from movart a'
      'join almacen b on a.almac = b.clave and a.cia = b.cia'
      'left outer join conceps c on a.nompro = c.ncon'
      'where codigo = :CODIGO and a.cia = :CIA'
      'and salio <> '#39'S'#39' order by exib desc, fecha, almac, folio'
      '')
    Left = 49
    Top = 440
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_mvartdisp: TDataSource
    DataSet = qry_mvartdisp
    Left = 81
    Top = 408
  end
  object PopupMenu1: TPopupMenu
    Left = 100
    Top = 377
    object Exportara1: TMenuItem
      Action = exporta_dbgrd
    end
    object GrabarEstadisAnual1: TMenuItem
      Action = graba_estadis_anual
    end
    object Permisiones1: TMenuItem
      Action = ver_permision
    end
    object Ofertas1: TMenuItem
      Action = desplegar_ofertas
    end
    object DesplegarHistoricoCostoReposicion1: TMenuItem
      Action = despliega_historico_costo_repo
    end
  end
  object qry_revision: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.tipo, a.alm, a.numero, b.codinv, b.folsal, b.folent, b.' +
        'entosal'
      
        'from entradas a join renentra b on a.tipo = b.tipo and a.numero ' +
        '= b.numero '
      'and a.alm = b.alm and a.cia=b.cia'
      'where a.fecha between :FECINI and :FECFIN and a.status = '#39'C'#39
      'and a.tipo <> '#39'G'#39' and a.tipo <> '#39'B'#39
      'order by a.tipo, a.alm, a.numero, b.codinv')
    Left = 472
    Top = 432
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end>
  end
  object qry_movto: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select almac, codigo, folio, serie, fecha, fechasal, salio from ' +
        'movart'
      'where codigo = :CODIGO and almac = :ALM and folio = :FOLIO')
    Left = 504
    Top = 432
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FOLIO'
        ParamType = ptUnknown
      end>
  end
  object qry_seriebus: TQuery
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'call buscaserie ( :CODIGO,  :SERIEBUS, :CIA )')
    Left = 537
    Top = 432
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'SERIEBUS'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_seriebus: TDataSource
    AutoEdit = False
    DataSet = qry_seriebus
    Left = 569
    Top = 432
  end
  object qry_descri2: TQuery
    OnCalcFields = qry_invenCalcFields
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select  d.concep as descri from inven a'
      
        'left outer join inv_invhist b on b.codigo = a.codigo and b.cia =' +
        ' a.cia'
      
        'left outer join inv_relinv c on c.idart = b.idart and c.idrel = ' +
        ':IDREL'
      'left outer join inv_conceps d on d.idconcep  = c.iddato'
      'where a.codigo = :Codigo and a.cia = :Cia'
      ''
      ' ')
    Left = 632
    Top = 464
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'Codigo'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'cia'
        ParamType = ptUnknown
      end>
  end
  object dts_descri2: TDataSource
    DataSet = qry_descri2
    Left = 633
    Top = 496
  end
  object qry_almreps: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave as alm, nombre  from almacen where cia = :CIA'
      'and ( status = :ACTIVO or status = :INACTIVO )'
      'order by status, zona, clave'
      ' ')
    Left = 664
    Top = 464
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ACTIVO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'INACTIVO'
        ParamType = ptUnknown
      end>
  end
  object dts_almreps: TDataSource
    DataSet = qry_almreps
    Left = 656
    Top = 448
  end
  object qry_extensa: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idextensa, a.idart, precioext, costoext'
      'from inv_invhist a join inv_extensa b on a.idart = b.idart'
      'where a.codigo = :CODIGO and a.cia = :CIA'
      ''
      ' ')
    Left = 314
    Top = 495
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_garantias: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select idgarantia, b.clave, b.descri, b.cia'
      'from inv_invhist a join inv_relinv c on a.idart = c.idart'
      'join inv_garantias b on c.iddato = b.idgarantia'
      'where a.codigo = :CODIGO and a.cia = :CIA and c.idrel = :IDREL'
      ''
      ' ')
    Left = 242
    Top = 415
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'IDREL'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxlin: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select tipo, plazomax from plazoscrd where linea= :LINEA and'
      
        '( tipo= :TIPO or tipo = :TIPO2 or tipo = :TIPO3 or tipo = :TIPO4' +
        ')'
      'and cia= :CIA')
    Left = 212
    Top = 416
    ParamData = <
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO3'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO4'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxprecio: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select plazomax from plazoscrd where tipo= :TIPO and cia= :CIA'
      '       and plistamax = ('
      '         select min(plistamax) from plazoscrd where tipo = :TIPO'
      '         and plistamax >= :PRECIO and cia= :CIA'
      '       )')
    Left = 212
    Top = 448
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PRECIO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxarticulo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select plazomax from plazoscrd a join inv_invhist b'
      'on a.idlinea = b.idart'
      'where tipo= :TIPO and a.cia= :CIA'
      'and b.codigo = :CODIGO')
    Left = 244
    Top = 448
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end>
  end
  object qry_plazoxgrupo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select plazomax from plazoscrd a join inv_grupos b'
      'on a.idlinea = b.idgrupo'
      'where tipo= :TIPO and a.cia= :CIA'
      'and b.codigo = :CODIGO'
      ' ')
    Left = 276
    Top = 448
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end>
  end
  object qry_grabaestadis: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select * from estadis where tipo = :TIPO and codigo = :CODIGO an' +
        'd anu = :ANU'
      'and cia = :CIA'
      ' ')
    Left = 683
    Top = 368
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object UpdateSQL1: TUpdateSQL
    ModifySQL.Strings = (
      'update estadis'
      'set'
      '  TIPO = :TIPO,'
      '  CODIGO = :CODIGO,'
      '  ALM = :ALM,'
      '  ANU = :ANU,'
      '  MES = :MES,'
      '  UNIDADES = :UNIDADES,'
      '  IMPORTE = :IMPORTE,'
      '  CIA = :CIA'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  CODIGO = :OLD_CODIGO and'
      '  ANU = :OLD_ANU and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into estadis'
      '  (TIPO, CODIGO, ALM, ANU, MES, UNIDADES, IMPORTE, CIA)'
      'values'
      '  (:TIPO, :CODIGO, :ALM, :ANU, :MES, :UNIDADES, :IMPORTE, :CIA)')
    DeleteSQL.Strings = (
      'delete from estadis'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  CODIGO = :OLD_CODIGO and'
      '  ANU = :OLD_ANU and'
      '  CIA = :OLD_CIA')
    Left = 684
    Top = 338
  end
  object qry_obslin: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from obslin  where linea = :LINEA and cia = :CIA'
      'order by moe desc, conse')
    Left = 720
    Top = 384
    ParamData = <
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_obslin: TDataSource
    DataSet = qry_obslin
    Left = 720
    Top = 416
  end
  object qry_observnegxcod: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from observent'
      
        'where tipo= :TIPOOBS and alm = :ALM and numero = :NUMERO and cod' +
        'igo = :CODIGO and cia = :CIA'
      'order by fecha desc, conse'
      ' ')
    Left = 758
    Top = 385
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_observnegxcod: TDataSource
    AutoEdit = False
    DataSet = qry_observnegxcod
    Left = 755
    Top = 416
  end
  object qry_observnegxpro: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from observent'
      
        'where alm = :ALM and tipo= :TIPOOBS and codigo = :CODIGO and num' +
        'ero = :NUMERO and cia = :CIA'
      'order by fecha desc, conse'
      ''
      ' ')
    Left = 790
    Top = 369
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_observnegxpro: TDataSource
    AutoEdit = False
    DataSet = qry_observnegxpro
    Left = 787
    Top = 400
  end
  object qry_observnegxmca: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from observent'
      
        'where alm = :ALM and tipo= :TIPOOBS and numero = :NUMERO and cod' +
        'igo = :CODIGO and cia = :CIA'
      'order by fecha desc, conse'
      ''
      ' '
      ' '
      ' ')
    Left = 822
    Top = 385
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_observnegxmca: TDataSource
    AutoEdit = False
    DataSet = qry_observnegxmca
    Left = 819
    Top = 416
  end
  object timer_cambioprecio: TTimer
    Enabled = False
    OnTimer = timer_cambioprecioTimer
    Left = 672
    Top = 261
  end
  object qry_obscomlin: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from observent'
      'where tipo= :TIPOOBS and alm = :ALM'
      'and numero = :NUMERO and codigo = :CODIGO and cia = :CIA'
      'order by fecha desc, conse'
      '')
    Left = 758
    Top = 448
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_obscomlin: TDataSource
    AutoEdit = False
    DataSet = qry_obscomlin
    Left = 757
    Top = 479
  end
  object qry_obscommca: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from observent'
      
        'where alm = :ALM and tipo= :TIPOOBS and codigo = :CODIGO and num' +
        'ero = :NUMERO and cia = :CIA'
      'order by fecha desc, conse'
      ''
      ' ')
    Left = 790
    Top = 449
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_obscommca: TDataSource
    AutoEdit = False
    DataSet = qry_obscommca
    Left = 790
    Top = 480
  end
  object qry_obscomgpo: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select * from observent'
      'where tipo= :TIPOOBS and alm = :ALM'
      'and numero = :NUMERO and codigo = :CODIGO and cia = :CIA'
      'order by fecha desc, conse'
      '')
    Left = 822
    Top = 448
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOOBS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_obscomgpo: TDataSource
    AutoEdit = False
    DataSet = qry_obscomgpo
    Left = 821
    Top = 479
  end
  object qry_catprodsat: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select c.idprod, c.codigo, c.descri'
      'from inv_invhist a join inv_relinv b'
      'on a.idart = b.idart and b.idrel = :TIPORELCOD'
      'join inv_catprodsat c on b.iddato = c.idprod'
      'where a.codigo=:CODIGO and a.cia = :CIA'
      '')
    Left = 147
    Top = 384
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPORELCOD'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_catprodsat: TDataSource
    DataSet = qry_catprodsat
    Left = 147
    Top = 416
  end
  object qry_catprodsatgpo: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select c.idprod, c.codigo, c.descri from inv_invhist a join inv_' +
        'relinv b'
      'on a.idart = b.idart and b.idrel = :TIPOREL'
      'join inv_grupos d on b.iddato = d.idgrupo'
      'join inv_catprodsat c on d.idcatprodsat = c.idprod'
      'where a.codigo=:CODIGO and a.cia = :CIA'
      '')
    Left = 147
    Top = 448
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPOREL'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_servicio: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.idart, a.codigo, a.impservicio, a.tipo, a.fecha, a.cia,'
      'b.linea, b.descri, d.descri as descrilin'
      'from inv_servicios a join inven b on a.codigo = b.codigo'
      'and a.cia = b.cia'
      'join inv_invhist c on a.idart = c.idart and a.cia = c.cia'
      'join inv_lineas d on b.linea = d.linea and a.cia = d.cia'
      'where a.codigo = :CODIGO and a.cia = :CIA and a.tipo = :TIPO'
      ' '
      ' ')
    Left = 144
    Top = 480
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end>
  end
  object qry_servxgpo: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.idart, b.codigo, a.impservicio, a.tipo, a.fecha, a.cia,'
      'b.descri'
      'from inv_invhist c join inv_relinv d'
      'on c.idart = d.idart and idrel = :REL_GRUPO'
      'join inv_grupos b on d.iddato = b.idgrupo'
      'join inv_servicios a on b.idgrupo = a.idart'
      'and a.cia = b.cia'
      'where c.codigo = :CODIGO and a.cia = :CIA and a.tipo = :TIPO'
      'order by b.codigo'
      '')
    Left = 184
    Top = 480
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'REL_GRUPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'TIPO'
        ParamType = ptUnknown
      end>
  end
  object qry_ofertas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.fecha, a.folio, a.fecini, a.fecfin, b.precmds'
      '        from inv_polofertas a'
      
        '        join inv_renpolofertas b on a.idpolcampre = b.idpolcampr' +
        'e'
      
        '        join inv_invhist d on b.idart = d.idart and a.cia = d.ci' +
        'a'
      '        join inven c on d.codigo = c.codigo and a.cia = c.cia'
      '        where a.fecha >= :FECHAMIN and'
      
        '        a.status = :STATUS_CAMBIOPRECIO and a.tipo = :TIPO_OFERT' +
        'A'
      '        and c.codigo = :CODIGO'
      
        '        and a.fecini >= :FECHAMIN and a.fecfin >= :FECHA and a.c' +
        'ia = :CIA'
      '        order by a.fecha desc'
      '')
    Left = 112
    Top = 480
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'FECHAMIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'STATUS_CAMBIOPRECIO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO_OFERTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHAMIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_historialofertas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.fecha, a.folio, a.fecini, a.fecfin, b.precmds'
      '        from inv_polofertas a'
      
        '        join inv_renpolofertas b on a.idpolcampre = b.idpolcampr' +
        'e'
      
        '        join inv_invhist d on b.idart = d.idart and a.cia = d.ci' +
        'a'
      '        join inven c on d.codigo = c.codigo and a.cia = c.cia'
      '        where a.tipo = :TIPO_OFERTA'
      '        and c.codigo = :CODIGO'
      '        and a.cia = :CIA'
      '        order by a.fecha desc'
      ' ')
    Left = 112
    Top = 520
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'TIPO_OFERTA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end
